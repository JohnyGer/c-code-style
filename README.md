# Recommended C Style and Coding Rules for Embedded System(Barr-C:2018 and MISRA C:2023 Compliant)

## General Rules

These rules align with common stylistic requirements in both standards to ensure safety, security, and maintainability.

### Language Standard
- **Language Standard:** Use the `C11` standard (ISO/IEC 9899:2011) or later. MISRA C:2023 explicitly supports C11 and C18 features, providing guidelines for safe use of features like atomics and multithreading.

### Formatting and Indentation
- **Indentation:** Use 4 spaces per indent level. Tabs are forbidden.
- **Keywords:** Use 1 space between keyword and opening bracket.
- **Functions:** No space between function name and opening bracket.

### Naming Conventions

**CRITICAL:** The following naming conventions are mandatory for compliance with **Barr-C** and **MISRA**:

1. `_` (underscore) as first or last character is reserved for C standard library
2. Avoid names differing only in case or underscore presence
3. Function and variable names must be entirely lowercase

#### Identifier Types and Conventions
- **Variables:** `snake_case`, lowercase (Example: `sensor_value`, `is_valid`)  
  Rule: Barr-C 7.1f, 7.1h; MISRA C:2023 Rules 5.1-5.5
- **Constants/Macros:** `UPPER_SNAKE_CASE` (Example: `MAX_BAUD_RATE`)  
  Rule: Barr-C 6.1f
- **Functions:** `snake_case`, lowercase (Example: `system_init()`)  
  Rule: Barr-C 6.1e, 6.1g
- **Types/Structs/Enums:** `snake_case` with `_t` suffix (Example: `sensor_data_t`)  
  Rule: Barr-C 5.1a
- **Files:** `snake_case`, lowercase with `.c`/`.h` suffix  
  Rule: Barr-C 2.1

### Braces and Spacing
- **Opening curly bracket always on same line as keyword**
- **Single space before/after operators, after commas**

```c
/* OK */
if (condition) {
    do_something();
} else {
    do_something_else();
}

a = 3 + 4;              /* OK */
func_name(5, 4);        /* OK */

/* Wrong */
if (condition){         /* Wrong brace position */
a=3+4;                  /* Wrong spacing */
func_name(4,3);         /* Wrong spacing */
```

### Variable Initialization
**CRITICAL:** Every variable must be initialized before first use (Barr-C:2018 Rule 3.2).

```c
/* OK - initialization in declaration */
static int32_t global_counter = 0;
static int32_t global_status = ERROR_NONE;

/* Wrong - uninitialized variables */
static int32_t a;       /* Wrong */
static int32_t b = 4;   /* Wrong */
```

### Variable Declaration
- **Declare same type variables in same line**
- **Declare in order: custom structs → integers → floating point**
- **Always declare at beginning of block**

```c
void
my_func(void) {
    /* Order: custom structs, integers, floats */
    my_struct_t my;     
    uint32_t a;
    int32_t b;
    char h;
    double d;
    float f;
}
```

### Data Types
- **Use stdint.h types except char, float, double**
- **Boolean types:** MISRA C:2023 supports `_Bool`; stdbool.h allowed for portability
- **Never compare against `true`**
- **Always compare pointers against `NULL`**

```c
/* OK */
uint8_t status = 0;
#include <stdbool.h>
bool status = false;

if (ptr == NULL) {      /* OK */
if (check_func()) {     /* OK - no true comparison */
```

### STRICTLY FORBIDDEN: Dynamic Memory and VLA
**CRITICAL:** MISRA C:2023 Rule 21.3 strictly forbids dynamic memory allocation.

```c
/* Wrong - violates MISRA C:2023 Rule 21.3 */
void my_func(size_t n) {
    int32_t* arr = malloc(sizeof(*arr) * n);  /* Forbidden */
    free(arr);                                 /* Forbidden */
}

/* Wrong - VLA forbidden */
void my_func(size_t n) {
    int32_t arr[n];  /* Forbidden */
}

/* CORRECT - use static allocation */
void my_func(size_t n) {
    static int32_t arr[MAX_SIZE];  /* OK */
    /* Use with bounds checking */
}
```

### Boolean and Comparison Rules
- **Compare variables against zero except boolean types**
- **Never compare boolean variables against 0 or 1. Use `!` instead**

```c
size_t length = 5;      /* Counter variable */
uint8_t is_ok = 0;      /* Boolean variable */

if (length > 0)         /* OK */
if (is_ok)              /* OK - boolean */
if (!is_ok)             /* OK - boolean negation */
if (is_ok == 1)         /* Wrong! */
```

## Comments
- **Always use `/* comment */`, never `//`**
- **Multi-line: space+asterisk for each line**
- **Use 12*4 spaces offset for comments**

```c
/* Single line comment (ok) */

/*
 * Multi-line comment (ok)
 * Proper formatting
 */

/* Comment aligned to 12*4 spaces */
```

## Functions
- **External functions MUST have prototypes**
- **Function names lowercase with optional underscore**
- **Align asterisk to return type for pointer functions**
- **Return type on separate line in implementation**

```c
/* OK */
void my_func(void);
const char* get_string(void);

int32_t
foo(void) {
    return 0;
}

/* Wrong */
void MYFunc(void);              /* Wrong case */
const char *get_string(void);   /* Wrong asterisk alignment */
```

## Variables
- **Variable names lowercase with optional underscore**
- **Group local variables by type**
- **Declare pointer variables with asterisk aligned to type**

```c
/* OK */
int32_t my_var;
char* ptr;

/* Wrong */
int32_t myVar;      /* Wrong case */
char *ptr;          /* Wrong asterisk alignment */
```

## Structures, Enumerations, Typedefs
- **Structure/enum names lowercase with optional underscore**
- **Structure members lowercase**
- **Enumeration members uppercase**
- **Use `_t` suffix for typedef**

```c
/* OK */
typedef struct {
    char* name;
    int32_t value;
} config_t;

typedef enum {
    STATE_OK,
    STATE_ERROR
} state_t;

/* Wrong */
typedef struct Config {  /* Wrong case */
    char* Name;          /* Wrong case */
} config;
```

### Structure Declaration Options
1. **Name only:** No `_t` suffix
2. **Typedef only:** Must have `_t` suffix  
3. **Name + typedef:** No `_t` for name, `_t` for typedef

```c
/* Option 1 - name only */
struct config {
    int32_t value;
};

/* Option 2 - typedef only */
typedef struct {
    int32_t value;
} config_t;

/* Option 3 - name + typedef */
typedef struct config {
    int32_t value;
} config_t;
```

## Compound Statements
- **Every compound statement MUST include curly brackets**
- **Single statement also requires brackets**
- **Empty loops must include brackets**

```c
/* OK */
if (condition) {
    do_something();
}

/* Wrong */
if (condition)        /* Missing brackets */
    do_something();
```

### Switch Statements
- **Single indent for each case**
- **Additional indent for break**
- **Always include default case**

```c
switch (value) {
    case 0:
        do_action();
        break;
    case 1:
        do_other();
        break;
    default:
        handle_error();
        break;
}
```

## Macros and Preprocessor Directives
- **Macros UPPER_SNAKE_CASE**
- **Protect all parameters and result with parentheses**
- **Multi-statement macros: use `do {} while (0)`**

```c
/* OK */
#define MIN(x, y)       ((x) < (y) ? (x) : (y))
#define SET_FLAG(flag)  do { flag = 1; } while (0)

/* Wrong */
#define MIN(x, y)       x < y ? x : y          /* Missing parentheses */
```

## Documentation
- **Use doxygen-style documentation with `\brief`, `\param`, `\return`**
- **Document all public functions, structures, variables**
- **Use `/*!<` for inline member documentation**

```c
/**
 * \brief           Initialize the system
 * \param[in]       config: System configuration
 * \return          0 on success, error code otherwise
 */
int32_t
system_init(const config_t* config);

/**
 * \brief           System configuration structure
 */
typedef struct {
    int32_t timeout;                    /*!< Timeout in milliseconds */
    bool enable_debug;                  /*!< Enable debug mode */
} config_t;
```

## Header/Source Files
- **Every file must include doxygen file header**
- **Header files must include guard and C++ check**
- **Include order: standard library first, then project headers**

```c
/**
 * \file            example.h
 * \brief           Example header file
 */

#ifndef EXAMPLE_HDR_H
#define EXAMPLE_HDR_H

#include <stdint.h>
#include "project_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Declarations here */

#ifdef __cplusplus
}
#endif

#endif
```

## Key Compliance Points

### MISRA C:2023 Critical Rules
- **Rule 21.3:** Dynamic memory allocation forbidden
- **Rule 17.2:** Recursion forbidden  
- **Rule 1.1:** Avoid undefined behavior
- **Rules 5.1-5.5:** Identifier requirements

### Barr-C:2018 Critical Rules
- **Rule 3.2:** Initialize all variables
- **Rule 7.1f, 7.1h:** Identifier naming
- **Rule 1.1d:** Prefer small functions
- **Rule 3.3:** Separate implementation from interface

### Critical Forbidden Practices
1. **Dynamic memory:** `malloc`, `free`, `calloc`, `realloc`
2. **VLA:** Variable Length Arrays
3. **Recursion:** All recursive functions
4. **Boolean comparison:** `== true`, `== false`
5. **Uninitialized variables:** Any variable used before initialization
6. **Magic numbers:** Undefined constants without `#define`

### Required Practices
1. **Static initialization:** All variables initialized at declaration
2. **Type safety:** Use stdint.h types, explicit casting
3. **Documentation:** All public interfaces documented with Doxygen
4. **Error handling:** All non-trivial functions return error codes
5. **Bounds checking:** All array accesses must be bounds-checked

## Summary

This coding standard ensures compliance with both Barr-C:2018 and MISRA C:2023 by:

- **Eliminating undefined behavior** through proper initialization and type usage
- **Preventing common C pitfalls** by forbidding dynamic memory and VLA
- **Ensuring code clarity** through consistent naming and formatting
- **Enabling static analysis** through deterministic patterns
- **Supporting maintainability** through comprehensive documentation

All code must pass MISRA C:2023 compliance checking and static analysis to be considered acceptable for production use in safety-critical embedded systems.

