# Writeprint Crusher
Prevents forensic linguistics.  Allows you to convert between identities (idiolects)

## Supports Switching Between:
* American-English, British-English, Australian-English, and Candian-English
* Hyphenated and non-hyphenated compound words
* Single spaces and double spaces after a period
* Capitalized and non-capitalized beginning of sentences
* Oxford and no Oxford comma
* Apostrophe or no apostrophe on words like won't and can't
* Commas before prepositions (FANBOYS)
* Periods between acronyms
* 12 hour and 24 hour
* mm-dd-yyyy to dd-mm-yyyy

## Analyzes Text:
* Warns of uncommon words or phrases

## What's This Used For?
Can be used for maintaining anonynimity when changing identities.

For example, if a user had multiple blogs, but didn't want their typing patterns link them together or to themselves, they could use Writeprint Crusher to convert their normal typing patterns into a different identity.  This makes it much harder to perform forensic linguistics to determine authorship.

## Usage
The program accepts text through a pipeline or through a file.

First, create a named identity: `./crusher --create-identity identity1`

A new file will be created in the folder the program was called which contains the configuration settings for the identity.

Second, use the identity and specify a file: `./crusher -i identity1.csv -f test.txt`

Alternatively, use the program in a pipeline: `cat tes.txt | ./crusher -i identity1.csv > out.txt`

Modifying the configuration files is encouraged.  values are stored as a 1 or 0 in a comma seperated list.

Values corrospond as follows:
`[TBD]`
### Notes
Only supported/tested on Linux.