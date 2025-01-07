#ifndef MYCLANG_LIBRARY_API_H
#define MYCLANG_LIBRARY_API_H

#ifdef __cplusplus
extern "C" {
#endif

/* Version information */
#define MYCLANG_VERSION_MAJOR 1
#define MYCLANG_VERSION_MINOR 0
#define MYCLANG_VERSION_PATCH 0

/* Maximum buffer sizes */
#define MYCLANG_MAX_NAME_LENGTH 256
#define MYCLANG_MAX_BUFFER_SIZE 4096

/* Status codes */
typedef enum {
    MYCLANG_SUCCESS = 0,
    MYCLANG_ERROR_INVALID_ARGUMENT = -1,
    MYCLANG_ERROR_BUFFER_OVERFLOW = -2,
    MYCLANG_ERROR_NOT_INITIALIZED = -3
} MyclangStatus;

/* Data structures */
typedef struct {
    char name[MYCLANG_MAX_NAME_LENGTH];
    unsigned int id;
    double value;
} MyclangObject;

/* Function declarations */
MyclangStatus myclang_initialize(void);
MyclangStatus myclang_cleanup(void);

MyclangStatus myclang_create_object(MyclangObject* obj, 
                                  const char* name,
                                  unsigned int id,
                                  double value);

MyclangStatus myclang_process_object(const MyclangObject* obj);

const char* myclang_get_version_string(void);

#ifdef __cplusplus
}
#endif

#endif /* MYCLANG_LIBRARY_API_H */
