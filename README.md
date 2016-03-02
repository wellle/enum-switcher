# enum-switcher

Auto generate functions that use `switch` statements to convert string
representations to IDs.

## Install

```
go get github.com/wellle/enum-switcher
```

## Usage

Consider a list of 584 timezones found in
[`example/timezones`](example/timezones):

```
$ head example/timezones
Africa/Abidjan
Africa/Accra
Africa/Addis_Ababa
Africa/Algiers
Africa/Asmara
Africa/Asmera
Africa/Bamako
Africa/Bangui
Africa/Banjul
Africa/Bissau
```

We want to map those to unique IDs from 0 to 583 in a way that is more
efficient that 584 string comparisons. With `enum-switcher` installed, you can
run a command like this:

```
$ head example/timezones | enum-switcher -format c > example/timezones.c
2016/02/29 00:16:35 nothing found yet, trying harder...
2016/02/29 00:16:35 found strategy with 1.30 expected checks
```

And find a C-style switch statement based conversion function like this:

```c
int convert(char* s) {
    switch(s[12]) {
        case '\0': return 1; // Africa/Accra
        case '_': return 2; // Africa/Addis_Ababa
        case 'i': return 7; // Africa/Bangui
        case 'l': return 8; // Africa/Banjul
        case 'o': return 6; // Africa/Bamako
        case 'r': return 3; // Africa/Algiers
        case 'u': return 9; // Africa/Bissau
        case 'a': switch(s[10]) {
            case 'a': return 4; // Africa/Asmara
            case 'd': return 0; // Africa/Abidjan
            case 'e': return 5; // Africa/Asmera
            default: return -1;
        }
        default: return -1;
    }
}
```

As you can see it chose to inspect the character at index 12 first to indentify
most of the timezones with a single access. Only for three of the ten examples
a second access is needed (at index 10). This explains the expected number of
accesses of 1.3 that was mentioned in the command output above. We try to
minimize this number, while currently assuming uniform distribution. It should
be straight forward to adapt the implementation to use any other given sample
distribution instead.

Generating the full function to convert all 584 timezones properly takes a few
seconds longer, but still manages to identify each one in a little over three
character accesses on average:

```
$ cat example/timezones | enum-switcher -format c > example/timezones.c
2016/02/29 00:09:47 nothing found yet, trying harder...
2016/02/29 00:09:47 nothing found yet, trying harder...
2016/02/29 00:09:47 nothing found yet, trying harder...
2016/02/29 00:09:52 nothing found yet, trying harder...
2016/02/29 00:10:11 found strategy with 3.18 expected checks
```

- find the full input of 584 timezones in [`example/timezones`](example/timezones)
- and the full generated conversion function in [`example/timezones.c`](example/timezones.c)

## Paranoid

If you need to handle all possible input, not only the given strings, then you can't take full advantage of the above optimizations. Use the `-paranoid` flag to generate the full tree:

```
$ cat example/timezones | enum-switcher -format c -paranoid > example/timezones-paranoid.c
```

You can see the result of that in [`example/timezones-paranoid.c`](example/timezones-paranoid.c)
