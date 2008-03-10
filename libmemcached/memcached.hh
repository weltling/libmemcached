#ifdef USE_PRAGMA_INTERFACE
#pragma interface                       /* gcc class implementation */
#endif

#include <memcached.h>
#include <string.h>
#include <stdio.h>

class Memcached
{
  memcached_st memc;

public:

  Memcached()
  {
    memcached_create(&memc);
  }

  Memcached(memcached_st *clone)
  {
    memcached_clone(&memc, clone);
  }

  char *get(char *key, size_t *value_length)
  {
    uint32_t flags;
    memcached_return rc;

    return memcached_get(&memc, key, strlen(key),
                         value_length, &flags, &rc);
  }

  char *get_by_key(char *master_key, char *key, size_t *value_length)
  {
    uint32_t flags;
    memcached_return rc;

    return memcached_get_by_key(&memc, master_key, strlen(master_key), key, strlen(key),
                                value_length, &flags, &rc);
  }

  memcached_return mget(char **keys, size_t *key_length, unsigned int number_of_keys)
  {

    return memcached_mget(&memc, keys, key_length, number_of_keys);
  }

  memcached_return set(char *key, char *value, size_t value_length)
  {
    return memcached_set(&memc, key, strlen(key),
                         value, value_length,
                         (time_t)0, (uint32_t)0);
  }

  memcached_return set_by_key(char *master_key, char *key, char *value, size_t value_length)
  {
    return memcached_set_by_key(&memc, master_key, strlen(master_key),
                         key, strlen(key),
                         value, value_length,
                         (time_t)0,
                         (uint32_t)0 );
  }


  memcached_return add(char *key, char *value, size_t value_length)
  {
    return memcached_add(&memc, key, strlen(key),
                 value, value_length,
                 (time_t)0, (uint32_t)0);
  }

  memcached_return replace(char *key, char *value, size_t value_length)
  {
    return memcached_replace(&memc, key, strlen(key),
                     value, value_length,
                     (time_t)0, (uint32_t)0);
  }

  memcached_return prepend(char *key, char *value, size_t value_length)
  {
    return memcached_prepend(&memc, key, strlen(key),
                    value, value_length,
                    (time_t)0,
                    (uint32_t)0);
  }


  memcached_return  append(char *key, char *value, size_t value_length)
  {
    return memcached_append(&memc, key, strlen(key),
                    value, value_length,
                    (time_t)0,
                    (uint32_t)0);
  }
 ~Memcached()
 {
   memcached_free(&memc);
 }
};
