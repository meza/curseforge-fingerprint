import path from 'node:path';
import url from 'node:url';
import curseforge from '../dist/esm/index.mjs';

const __dirname = url.fileURLToPath(new URL('.', import.meta.url));

const file1 = path.resolve(__dirname, '__fixtures__', 'test1.md');
const file2 = path.resolve(__dirname, '__fixtures__', 'test2.md');
const expectedFile1Fingerprint = 3608199863;
const expectedFile2Fingerprint = 3493718775;

const result1 = curseforge.fingerprint(file1);
const result2 = curseforge.fingerprint(file2);

if (result1 !== expectedFile1Fingerprint) {
  throw new Error('Fingerprint 1 did not match the expectations');
}

if (result2 !== expectedFile2Fingerprint) {
  throw new Error('Fingerprint 2 did not match the expectations');
}

console.log('All tests pass');

export {};
