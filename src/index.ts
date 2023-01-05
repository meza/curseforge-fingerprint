import { createRequire } from 'module';

const curseforge = createRequire(import.meta.url)('../addon/curseforge.node');

export interface Curseforge {
  fingerprint: (filePath: string) => number;
}

export default curseforge as Curseforge;
