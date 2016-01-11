# libhashtable

[![travis build icon](https://travis-ci.org/jlagneau/libhashtable.svg)](https://travis-ci.org/jlagneau/libhashtable)

This is a really simple hashtable library in C.

---

## Installation

    make && make test

There's no make install. Copy the file manually if you need to.

## Simple use case

    #include <libhashtable.h>

    /*
    ** Create a function to delete your table content.
    */
    void    delete(void *e)
    {
        (void)e;
    }

    int     main(void)
    {
        t_hashtable *h;

        h = ht_create(&delete);
        ht_set(h, "randomKey1", "Content");
        printf("%s\n", ht_get(h, "randomKey1"));
        ht_delete(&h);
        return (0);
    }

For more advanced use cases, read the tests or source code.
