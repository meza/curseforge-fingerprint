import { createRequire } from 'node:module';
import path from 'node:path';
import * as url from 'node:url';

export interface Curseforge {
  fingerprint: (filePath: string) => number;
}

const __dirname = url.fileURLToPath(new URL('.', import.meta.url));
const curseforge: Curseforge = createRequire(import.meta.url)('node-gyp-build')(path.resolve(__dirname, '../../'));

export default curseforge as Curseforge;
