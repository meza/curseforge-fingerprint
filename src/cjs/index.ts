const path = require('node:path');
const curseforge = require('node-gyp-build')(path.resolve(__dirname, '../../'));

export interface Curseforge {
  fingerprint: (filePath: string) => number;
}

module.exports = curseforge as Curseforge;
