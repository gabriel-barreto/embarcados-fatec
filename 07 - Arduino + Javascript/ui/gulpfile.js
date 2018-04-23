const autoprefixer = require('gulp-autoprefixer');
const babel = require('gulp-babel');
const clean = require('gulp-clean');
const copy = require('gulp-copy');
const gulp = require('gulp');
const notify = require('gulp-notify');
const runSequence = require('run-sequence');
const sass = require('gulp-sass');
const sourcemaps = require('gulp-sourcemaps');

const assets = '**/*.svg';

gulp.task('clean:dist', () => gulp.src('./dist/**/*.*').pipe(clean()));
gulp.task('clean:index', () => gulp.src('./dist/index.html').pipe(clean()));
gulp.task('clean:assets', () => gulp.src(`./dist/${assets}`));
gulp.task('clean:scripts', () =>
    gulp.src('./dist/scripts/**/*.*').pipe(clean()),
);
gulp.task('clean:stylesheets', () =>
    gulp.src('./dist/stylesheets/**/*.*').pipe(clean()),
);

gulp.task('compile:sass', ['clean:stylesheets'], () =>
    gulp
        .src('./src/stylesheets/main.sass')
        .pipe(sourcemaps.init())
        .pipe(
            sass().on(
                'error',
                notify.onError({
                    title: 'Sass Compiler Error',
                    message: '<%= error.message %>',
                    templateOptions: {
                        date: new Date(),
                    },
                }),
            ),
        )
        .pipe(
            autoprefixer({
                browsers: ['last 3 version'],
                cascade: false,
            }),
        )
        .pipe(sourcemaps.write('.'))
        .pipe(gulp.dest('./dist/stylesheets/')),
);

gulp.task('compile:script', ['clean:scripts'], () =>
    gulp
        .src('./src/scripts/main.js')
        .pipe(
            babel({
                presets: ['env', 'stage-3'],
            }),
        )
        .pipe(gulp.dest('./dist/scripts/')),
);

gulp.task('copy:index', ['clean:index'], () =>
    gulp.src('./src/index.html').pipe(copy('./dist/', { prefix: 1 })),
);

gulp.task('copy:assets', ['clean:assets'], () => (
    gulp.src(`./src/${assets}`)
        .pipe(copy('./dist', { prefix: 1 }))
));

gulp.task('watch', ['clean:dist'], () => {
    gulp.watch('./src/stylesheets/**/*.sass', ['compile:sass']);
    gulp.watch('./src/scripts/**/*.js', ['compile:script']);
});

gulp.task('default', ['clean:dist'], (cb) =>
    runSequence([
        'copy:index',
        'copy:assets',
        'compile:sass', 
        'compile:script'
    ], cb),
);
