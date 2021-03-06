/**
 * A very basic hashtable implementation
 *
 * @author  Daniel Hong
 * 
 * This program is licensed under the GNU GENERAL PUBLIC LICENSE Version 2.
 * A LICENSE file should have accompanied this program.
 */

#ifndef _DH_HASHTABLE_H_
#define _DH_HASHTABLE_H_

#include "../../c-functions/include/class.h"

struct HTEntry_s {
    char *key;
    char *value;
    struct HTEntry_s *next;
};

typedef struct HTEntry_s HTEntry;

CLASS(Hashtable,
    /**
     * Add a new hash entry
     *
     * @param   Hashtable *     Pointer to a Hashtable structure created from init_hashtable()
     * @param   char *          The key
     * @param   char *          The value
     */
    FUNC(void, add, (struct Hashtable *, char *, char *));
    
    /**
     * Update an existing hash entry
     *
     * @param   Hashtable *     Pointer to a Hashtable structure created from init_hashtable()
     * @param   char *          The key for the value to update
     * @param   char *          The new value
     */
    FUNC(void, update, (struct Hashtable *, char *, char *));
    
    /**
     * Get a hash entry
     *
     * @param   Hashtable *     Pointer to a Hashtable structure created from init_hashtable()
     * @param   const char *    The key whose value to get
     * @param   const char *    A default value to return if the key doesn't exist
     * @return  coonst char *   The value of given key, or default value passed in
     */
    FUNC(const char *, get, (struct Hashtable *, const char *, const char *));
    
     /**
     * Remove a hash entry
     *
     * @param   Hashtable *     Pointer to a Hashtable structure created from init_hashtable()
     * @param   const char *    The key of the entry to remove
     */
    FUNC(void, remove, (struct Hashtable *, const char *));
    
     /**
     * Checks if a hash entry exists for a given key
     *
     * @param   Hashtable *     Pointer to a Hashtable structure created from init_hashtable()
     * @param   const char *    The key to check
     * @return  int             Returns 1 if it exists, 0 if it doesn't
     */
    FUNC(int, contains_key, (struct Hashtable *, const char *));
    
    // -------------------------------------------------------------------------
    //  Below are private properties and methods
    //  These should not be used as they can change at any time without notice
    //  and as such are not documented
    // -------------------------------------------------------------------------
    
    int _size;
    struct HTEntry_s **_table;
    FUNC(HTEntry *, _newitem, (char *, char *));
    FUNC(void, _add_update, (struct Hashtable *, char *, char *));
    FUNC(int, _hash, (const char *));
);

/**
 * Instantiate a Hashtable structure. This function would be equivalent to 
 * the "new" keyword in C++. Objects created by this function must be released
 * using the free_hashtable() function.
 *
 * @return  Hashtable *     Pointer to an Hashtable structure. Returns
 *                          NULL on error.
 */
Hashtable *init_hashtable();

/**
 * Free memory that was allocated for the hashtable
 *
 * @param   Hashtable *     The Hashtable pointer to free up
 */
void free_hashtable(Hashtable *);

// -----------------------------------------------------------------------------
//  Function pointers.
// -----------------------------------------------------------------------------

static void _add_(Hashtable *, char *, char *);
static void _update_(Hashtable *, char *, char *);
static const char *_get_(Hashtable *, const char *, const char *);
static void _remove_(Hashtable *, const char *);
static int _contains_key_(Hashtable *, const char *);
static HTEntry *_newitem_(char *, char *);
static int _hash_(const char *);
static void _add_update_(Hashtable *, char *, char *);

#endif /* _DH_HASHTABLE_H_ */

