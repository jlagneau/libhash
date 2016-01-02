# libhash

![](https://travis-ci.org/jlagneau/libhash.svg)

---

This is a really simple hash library in C.

## Installation

    make && make test

There's no make install. Copy the file manually if you need to.

## Simple use case

    #include <libhash.h>

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
