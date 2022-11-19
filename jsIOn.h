/*
jsIOn.c
JavaScript (Input/Output Object) Notation

Copyright 2022 Joseph Arnusch

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation 
files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, 
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/


#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

typedef enum {
    jsonNULL,
    jsonBOOL,
    jsonINT,
    jsonDOUBLE,
    jsonSTRING,
    jsonARRAY,
    jsonOBJECT
} value_type;

typedef struct json_data {
    struct json_data *next;
    struct json_data *child;
    struct json_data *last;

    value_type json_value_type;

    char *key;

    char *j_string;
    int j_integer;
    double j_double;


} JSONdata;

#define IS_JSON(json_object, jType) (json_object->json_value_type == jType) 
#define JSON_CONTAINER (jsonOBJECT || jsonARRAY)

void clear_json(JSONdata *j);
void write_json(const char *file_name, JSONdata *object);
void add_to_object(JSONdata *container, JSONdata *item);

JSONdata *create_json_array(const char *key);
JSONdata *create_json_object(const char *key);
JSONdata *create_json_string(const char *key, const char *variable);
JSONdata *create_json_integer(const char *key, int variable);
JSONdata *create_json_double(const char *key, double variable);
JSONdata *create_json_bool(const char *key, int variable);

// Config Data

#define JSON_BUFFER_STRING ("  ")
#define JSON_MAX_VALUE_BUFFER (1024 * 1000)
#define JSON_MAX_KEY_BUFFER (1024 * 1)