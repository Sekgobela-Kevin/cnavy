# CNavy search
> simple small search engine in C/C++
## Description
Cnavy search is a simple search engine for searching through files and webpages with C/C++.
The C represent C\C++ languges with navy named from [Datanavy search](datanavy.site).
Datanavy search was written in Python using Spacy, Numpy and other libraries.  

## About Datanavy search
Datanavy search was intended for learning Python back in 2021.
It included both code for searching, crawling and displaying results in browser.
Crawling was done with requests, beutifulsoup, Pdfminer.six, pydocx and pypdf forsupporting different formats
Text proccessing was handled by NLTK and Spacy frameworks.
Search portion was using Numpy for working with numbers generated from indexes from Spacy tokens.  

For searver side it was using Flask for its simplicity and Javascript, CSS and HTML for displaying data 
in browser. It was hosted in [datanavy.site](datanavy.site) at [pythonanywhere.com](pythonanywhere.com) until
being shutdown. It was challenging when creating the search engine especially client-side(browser) since I
had no knowledge of client-server programming including HTTP.

Client side libraries for Datanavy search include W3.CSS, W3.JS, AngularJS and JQuery  
Server-side libraries included Spacy, NLTK, Numpy, Beautysoup, Pydocx, Pypptx, Pdfminer.six and Flask.

> Datanavy search is in private repository,
> check [pynavy](https://github.com/Sekgobela-Kevin/pynavy) for similar repo

## About Cnavy search
Cnavy search has similar purpose as Datanavy search in that files and webpages get searched.
Cnavy search doesnt code for generating webpages but searching will be conducted through command-line.
Creating webpages would require setting up servers and creating html files which can be time consuming.
It will also require JavaScript which would add more layer of development on creating the search engine.
The repository will only contain enough to to create an executable that allows searching with commands like
cnavy search --query "food chain".  

It can be easy create command-line interface than webserver interface which requires lot of configuarations and
installing of more softwares. When developing Datanavy search, lot of time was spent on client side learning
how to use JS and CSS frameworks other than the search code. More time was supposed to be used on Python but ended
stuck on client-server communication. That was bad but introdused me how web technologies work together until
a webpage is rendered to the client.  

Displaying search results on web can be done in seperate repository using maybe React/Bootstrap. Advantage is that
it could be used by Pynavy, Datanavy and also Cnavy search unlike the one included in Datanavy search. One thing
to do is not to repeat the same mistakes in Datanavy search. Starting to code without planning on how different
parts work together would bring problems that may require rewrite.

### Cnavy search structure
Cnavy is divided into portions that perform certain portion from crawling for text data to performing a
search. Search can be performed with something like _cnavy search --query "food chain"_ which returns
results piped to _less_ or similar program. 
>Basic parts include Crawler, RSM, XTess and Angral

#### Crawler
Crawler portion which is responsible for extracting text data from files and webpages. CPR(C++ curl) and myhtml are
used for working with webpages and urls. Crawler responsibility is to locate resources(what to be searched) and 
then extract text data from them. Resources could be files(pdf, .txt), webpages or any medium that can provide
text data. Support for file format would depend on availability of libraries for that specific file format.

#### RSM(Resources Manager)
**RSM** stands for Resources Manager and its purpose is to manage resources. Resources can be unproccessed(raw) 
from crawler or proccessed from XTess. XTess is portion responsible for proccessing text. RSM manages resources
for Cnavy and includes database for storing resources to span multiple sessions. It should also provide clean
interface for XTess to access data from Crawler or Angral to access XTess data.
> Angral is portion for searching  

#### XTess
**XTess** proccesses text to make it easy to be worked. It is currently written from scratch and makes up te most
of the application code. XTess is expected to be written without any third-party library. All text proccessing 
should be done manually based on what is discovered in the text. Lot of developmet time was spent here and it 
makes up most of commits and files.  

The latest Classes are Basic_Character and Basic_Token which represent characters and tokens in text after 
perfroming basic tokenisation/tokenization(american). Lot needs to be done with Basic_Tokens and Basic_Characters 
up until Tokens get created. Datanavy search was using Spacy which performs all text proccessing and then exposing
tokens which code can use. Basic_Tokens are tokens without context data, same words have same Basic_Token object
they shared.  
> Completing XTess is a goal to be archived

#### Angral
**Angral** named after word _Engine_ is used for search related functionality such as ranking results and 
searching. It uses proccessed data XTess with query as input including data about which resources
to searched. It should allow choosing which resources to be searched so that only neccessay resources get
searched.
> Cnavy is name of application and Angral is portion for searching  
  
> Angral has not yet started

see [issue 9 comment](https://github.com/Sekgobela-Kevin/cnavy/issues/9#issuecomment-1107372130) for more about
Crawler, RSM, XTess and Angral.  
see [CMake project structure](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand project structure beyond the mentioned.

## Usage
```bash _cnavy search --query [query]```   - should search for _query_ and return results in command-line.  
```bash cnavy search --type [search type]``` - specifies type of search to use, [keywords] would use only keywords search.  

```bash cnavy search --max-results [int]``` - specifies maximum results to return.  
```bash cnavy search --min-relevance [percents]``` - specifies relevence to consider result as relevance. 
                                            - Results below this will be considered not relevant.
  
```bash cnavy search --exclude [resource] --query [query]```   - excludes  resourse from being searched.
```bash cnavy search --include [resource] --query [query]```   - includes  resourse from being searched.
 
```bash cnavy resources --add [resource-locator]``` - Add resource from source(path, url, etc).
```bash cnavy resources --add -text [text] -title [text]``` - Add text as resource and specify title of the text.  
 
```bash cnavy resources --proccess [resources]``` proccesses resources with XTess
```bash cnavy resources --proccess all``` proccesses all added resources
```bash cnavy resources --proccess -remove [resources]``` remove proccessed resource
 
```bash cnavy resources -stutus [resources]``` displays status of resource  

## Building and running
see [running CMake project](https://cliutils.gitlab.io/modern-cmake/chapters/intro/running.html) to build and run application.  

```bash cd project-dir``` - into project source directory.  
```bash cmake -S . -B build``` - to configure into build/ directory.  
```bash cmake --build build``` - to run build all target into build/  
```bash cmake --build build --target cnavy``` - to build cnavy executable  
```bash cmake --build build --target tests``` - to build tests executable powered by doctest  
```bash cmake --build build --target tests_proto``` - to build tests_proto executable(source in tests/tests_proto.cpp)


## Support
Feel free to pen an issue or contact me on [kevinnoko23@gmail.com](mailto:kevinnoko23@gmail.com).  

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Make changes as you wish, you wont break anything.  
Also update tests to match latest changes.

## Authors and acknowledgment
I am the only contributor and I am still learning how to use C++ from Python.  
You can also contribute to the project or add new feature.  
Try it out and to learn something new, you wont break anything.

## Project status
The project is still under development most features still missing. Currently XTess is still under developmet
with RSM and Crawler partialy developed. Angral has not yet received any development but will be developed as 
soon as XTess is completed.   

Its taking too long to finish this project than planned. If it continues, some features will be stripped and 
Cnavy search made to be just keyword search. I cant wait for another month of development and learning new 
lanuguages related to C++ development.  

## License
[GPL-3.0 License](https://github.com/Sekgobela-Kevin/cnavy/blob/main/LICENSE)
