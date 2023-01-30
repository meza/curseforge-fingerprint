import path from 'node:path';
import {createRequire} from 'module';
import * as url from 'url';
const __dirname = url.fileURLToPath(new URL('.', import.meta.url));

const curseforge = createRequire(import.meta.url)('node-gyp-build')(path.resolve(__dirname, '../../'));

export interface Curseforge {
  fingerprint: (filePath: string) => number;
}

export default curseforge as Curseforge;
