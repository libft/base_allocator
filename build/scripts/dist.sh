#!/bin/sh

rm -rf dist
mkdir -p dist/includes
cp build/release/a/lib*.a dist
cp build/release/so/lib*.so dist
cp -r src/includes dist

(cd dist && zip -r release.zip lib*.a lib*.so includes)
(cd dist/includes && zip -r ../headers.zip -- *)
(cd src && zip -r ../dist/source.zip ./*)
rm -rf dist/includes
