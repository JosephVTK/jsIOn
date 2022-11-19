# jsIOn Readme

The readme file for the drop in JavaScript (Input/Output Object) Notation module for C.

## Basic Operation (Output)

### Includes

---
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "jsIOn.h"
```


---
### Initialize Some Containers

---
```
JSONdata *object;
JSONdata *array;
```
---
### Create Our Initial Object

---
```
object = jsonCreateObject(NULL); // Create our initial (base) object

```
---
### Add Some Attributes To The Object

---
```
// Add to our object

// jsonAddObject(object, jsonCreateOBJECT_TYPE(KEY, VALUE));

jsonAddObject(object, jsonCreateString("name", "JsonData"));
jsonAddObject(object, jsonCreateInt("age", 14));
jsonAddObject(object, jsonCreateBool("likeable", TRUE));
```

### Create An Array For Our Object

---
```
array = jsonCreateArray("Favourite Ice Creams"); // Create an Array and give it a key
``` 
### Fill Array

---
```
// Fill Array
jsonAddObject(array, jsonCreateString(NULL, "Chocolate"));
jsonAddObject(array, jsonCreateString(NULL, "Vanilla"));
jsonAddObject(array, jsonCreateString(NULL, "Strawberry"));

``` 
### Add Array To Object

---
```

// Add the array to our original object
jsonAddObject(object, array);
```
### Do Something With It

---
```
// Write it to disk
json_write_to_disk("test_file.json", object);
```
## IMPORTANT

---
```
// IMPORTANT
// IMPORTANT
// IMPORTANT
// Make sure to free the memory when you are done using the json data.
// json_free_object will free it's memory as well as all it's dependant json objects.
json_free_object(object);
```

## Basic Operation (Input)

```
Code
```