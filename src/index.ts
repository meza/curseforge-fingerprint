const curseforge = require('node-gyp-build')('curseforge.node');

export interface Curseforge {
  fingerprint: (filePath: string) => number;
}

module.exports = curseforge as Curseforge;
