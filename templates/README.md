# C++ Templates

Reusable C++ templates and snippets for competitive programming.

These files are intended to be copied or used as a starting point when solving problems. They are different from the implementations in `algorithms/`, which are mainly for learning and understanding.

## Available Templates

```text
templates/
├── cp.cpp
└── ...
```

### `cp.cpp`

Basic competitive programming template containing:

* Common type aliases
* Common constants
* `all()` / `rall()` macros
* `solve()` function
* Fast I/O
* Local input/output redirection

## Using the Template

You can copy `cp.cpp` to the directory where you are solving a problem:

```bash
cp templates/cp.cpp problems/codeforces/<problem>/main.cpp
```

Or simply open `cp.cpp` and copy the code into a new solution file.

## VS Code Snippets

The repository also contains snippets that can be configured in VS Code.

### 1. Open C++ User Snippets

In VS Code:

`Ctrl + Shift + P`

Search for:

```text
Snippets: Configure Snippets
```

Select:

```text
cpp.json
```

This opens the C++ user snippets file.

### 2. Add the Template Snippet

Add the `Competitive Programming Template` snippet:

```jsonc
"Competitive Programming Template": {
    // Type "cp" to trigger this snippet
    "prefix": "cp",

    // The code that will be inserted
    "body": [ 
        // paste template code here
        "#include <bits/stdc++.h>",
        "using namespace std;",
        "",
        
        "    return 0;",
        "}"
    ],
    "description": "C++ Competitive Programming template"
}
```

After saving, open a `.cpp` file and type:

```text
cp
```

Then select the snippet or press `Tab` if autocomplete is configured to accept it.
