export interface Curseforge {
  fingerprint: (filePath: string) => number;
}
const path = require('node:path');
const curseforge: Curseforge = require('node-gyp-build')(path.resolve(__dirname, '../../'));

module.exports = curseforge as Curseforge;
