File (Field) Paths
==================

The File (Field) Paths module extends the default functionality of Backdrop's core
File module, Image module and many other File upload modules, by adding the
ability to use entity based tokens in destination paths and file names.

In simple terms, File (Field) Paths allows you to automatically sort and rename
your uploaded files using token based replacement patterns to maintain a nice
clean filesystem.

Features
--------

* Configurable file paths now use entity tokens in addition to user tokens.
* Configurable file names.
* Support for file based fields, including but not limited to:
    * Backdrop core File module.
    * Backdrop core Image module.
    * Video module.
* File path and filename cleanup options:
    * Remove slashes from tokens.
    * Filter out words and punctuation by taking advantage of the Path
      module.
    * Convert unicode characters into US-ASCII with core transliteration.
* Automatically updates unprocessed file paths in any Text fields on the entity.
* Retroactive updates - rename and/or move previously uploaded files.
* Active updating - actively rename and/or move previously uploaded files.
* Create redirect - automatically create a redirect when moving uploaded files,
  using the Redirect module.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/filefield_paths/issues


Current Maintainers
-----------------

- [Indigoxela](https://github.com/indigoxela)
- Co-maintainers welcome!

File (Field) Paths has been ported to Backdrop CMS by Leonid Kolesnik
([kleomash](https://github.com/kleomash)).

Credits
------

Originally written for Drupal by Stuart Clark (deciphered).

* http://stuar.tc/lark
* http://twitter.com/Decipher

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
