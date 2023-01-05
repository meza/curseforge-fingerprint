const curseforge = require('../addon/curseforge.node');

export interface Curseforge {
  fingerprint: (filePath: string) => number;
}

export default curseforge as Curseforge;
