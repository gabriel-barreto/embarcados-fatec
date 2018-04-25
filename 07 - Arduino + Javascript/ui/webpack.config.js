// --> Dependencies
const path = require('path');

// --> Plugins
const cleanPlugin = require('clean-webpack-plugin');
const copyPlugin = require('copy-webpack-plugin');
const extractTextPlugin = require('extract-text-webpack-plugin');

// --> Constants
const basePath = path.join(__dirname, 'src');
const buildPath = path.join(__dirname, 'dist');
const pathToCopy = [
    {
        from: path.join(basePath, 'images', '**', '*.*'),
        to: path.join(buildPath, 'images'),
        flatten: true,
    },
    { from: path.join(basePath, 'index.html'), to: buildPath },
];
const extractSass = new extractTextPlugin({ filename: 'stylesheets/[name].css' });

const config = {
    entry: {
        'bundle': path.join(basePath, 'scripts', 'main.js'),
        // 'stylesheets/main.css': path.join(basePath, 'stylesheets', 'main.sass'),
    },
    output: {
        path: buildPath,
        filename: 'scripts/[name].js',
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                loader: 'babel-loader',
            },
            {
                test: /\.sass$/,
                exclude: /node_modules/,
                use: extractSass.extract({
                    use: [{ loader: 'css-loader' }, { loader: 'sass-loader' }],
                }),
            },
        ],
    },
    plugins: [
        new cleanPlugin(buildPath),
        new copyPlugin(pathToCopy),
        extractSass,
    ],
};

module.exports = config;
