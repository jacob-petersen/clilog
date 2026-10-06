# clilog

Very much a work in progress.

# Build instructions:
`cmake` required.

1. Clone this repo.
2. `mkdir build`
3. `cd build`
4. `cmake ..`
5. `make`
 
# Design philosophy

I am not overcomplicating things. This software will be split into three separate concerns:
- Presentation
- Logic
- Persistence

This is a logical separation, not necessarily how the project files are organized.

## Presentation
UI. The UI does not process anything meaningful. All it does is send data to and from the Logic layer.

## Logic
All the processing of data happens here. Validating input fields, etc. It makes calls to the Persistence layer to store and retrieve data, and pass it up to the UI if necessary.

## Persistence
Peristent data storage. Presents interfaces to the Logic layer. Low level file storage, databases, etc. live here exclusively.