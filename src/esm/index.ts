import path from 'node:path';
import { createRequire } from 'module';
import * as url from 'url';

export interface Curseforge {
  fingerprint: (filePath: string) => number;
}

const __dirname = url.fileURLToPath(new URL('.', import.meta.url));
const curseforge: Curseforge = createRequire(import.meta.url)('node-gyp-build')(path.resolve(__dirname, '../../'));

export default curseforge as Curseforge;
