import curseforge from '../dist/esm/index.mjs.js';
import path from 'node:path';
import url from 'url';
const __dirname = url.fileURLToPath(new URL('.', import.meta.url));

const file1 = path.resolve(__dirname, '__fixtures__', 'test1.md');
const file2 = path.resolve(__dirname, '__fixtures__', 'test2.md');

const result1 = curseforge.fingerprint(file1);
const result2 = curseforge.fingerprint(file2);

if (result1 !== 3608199863) {
  throw new Error('Fingerprint 1 did not match the expectations');
}

if (result2 !== 3493718775) {
  throw new Error('Fingerprint 2 did not match the expectations');
}

console.log('All tests pass');

export {};
