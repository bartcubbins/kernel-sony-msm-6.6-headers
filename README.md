# common-headers-6.6

Kernel UAPI headers for `kernel/sony/msm-X.Y`, installed by
`cp_headers.py`.

## Layout

    common-headers/
    ├── Android.bp
    ├── cp_headers.py
    ├── kernel-headers/
    └── techpack-headers/
        └── <name>/

- `kernel-headers/` - kernel UAPI and architecture-specific headers
  (`qti_kernel_headers_X.Y`).
- `techpack-headers/` - headers from individual techpacks
  (`qti_*_X.Y`).

Header paths are preserved relative to their source roots. Techpacks
with multiple header modules, such as `dataipa` and `securemsm`,
share a directory.

## Usage

    python3 cp_headers.py [-v]

The script expects kernel sources in `../kernel` and a host C
compiler to build `unifdef`.

Set `UNIFDEF` to use an existing binary or `CC` to select a compiler.

- Headers are installed using the kernel's `headers_install.sh`,
  following the same approach as CLO.
- Headers already provided by bionic are skipped to avoid shadowing
  its copies.
- Each header is marked as `new`, `updated`, or `unchanged`
  compared to the previous run.
- Use `-v` to print every header, including unchanged ones.
- Only the generated section of `Android.bp` is updated. If any
  header fails to install, `Android.bp` is left untouched.

The log is written to
`out/kernel-X.Y/cp_headers.log` under the Android tree root.

The script exits with code `1` if any errors occur.

## Configuration

Edit `CORE_ROOTS` and `TECHPACKS` in `cp_headers.py` to change
which headers are installed.

Each root can be either:

- A directory - installs all `.h` files recursively.
- A tuple of a directory and a file list - installs only the
  specified headers relative to that directory.

For example:

    ("path/to/headers", ["foo.h", "bar/baz.h"])
