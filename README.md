#
curseforge-fingerprint

Node binding for the fingerprinting algorithm curseforge is using.

This is using the exact c++ source code that Curseforge is using to determine file fingerprints.
It's wrapped into a node addon so that it could be reused elsewhere.

# Install

This is a native binding which means that it uses `node-gyp` to compile the C++ code into something node can use.
Compilation depends on your operating system.

> **IMPORTANT**
>
> [Follow the instructions here](https://www.npmjs.com/package/node-gyp) to install all the required dependencies.
>

Once the dependencies for `node-gyp` are satisfied, then install the module itself. These dependencies are required to
build the module on the system you are working on.

This also means that the project you use this for will also be platform-dependent. This might change later.


npm: `npm install @meza/curseforge-fingerprint`

yarn: `yarn add @meza/curseforge-fingerprint`

pnpm: `pnpm add @meza/curseforge-fingerprint`

# Usage

```javascript

import curseforge from '@meza/curseforge-fingerprint';
import path from 'path';

const file = path.resolve('/path/to/jar');
const fingerprint = curseforge.fingerprint(file);

```

# Please Help

If you can help make the c++ code cleaner or to make the node module more user friendly, please submit a pull request.
