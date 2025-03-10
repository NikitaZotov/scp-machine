# Quick Start

## Use scp-machine as an extension to sc-machine

### GitHub Releases

Note: currently, using scp-machine natively on Windows isn't supported.

1. Download pre-built artifacts of sc-machine from [GitHub Releases](https://github.com/ostis-ai/sc-machine/releases) and extract it to any location.
    
    To learn more about how to install and use sc-machine artifacts, see [sc-machine quick start](https://ostis-ai.github.io/sc-machine/quick_start/).

2. Download pre-built artifacts of scp-machine from [GitHub Releases](https://github.com/ostis-ai/scp-machine/releases) and extract it to any location.

3. Then specify the folder path to `lib/extensions` from extracted scp-machine folder when running the sc-machine binary:

```sh
./path/to/sc-machine/binary -s path/to/kb.bin \
    -e "path/to/extracted/scp-machine/lib/extensions;path/to/sc-machine/lib/extensions"
# if several paths to extensions are provided then they should be separated 
# by semicolon and wrapped in double quotes
```

In case you want to make changes to the project sources, please refer to the [build system docs](build/build_system.md).
