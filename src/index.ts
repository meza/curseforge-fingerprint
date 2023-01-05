import curseforge from '../addon/curseforge.node';

interface Curseforge {
  fingerprint: (filePath: string) => number;
}

export default curseforge as Curseforge;
