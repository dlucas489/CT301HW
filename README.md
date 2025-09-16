This homework assignment implements an input validator and formatter for Game of Life boards. HW1.cpp acts as a driver. It accepts a filename as runtime argument, then invokes parseFile, and prints either the normalized output (1D binary string, then 2D board) or reports errors via reportAndReturn. Error handling is graceful. File issues and parse failures throw ParserError with a 0-based line index.  <br>
<br> The parsing logic is in parser.h/cpp. The ParseResult struct carries both dimensions. Helper functions enforce file format. convertCellChars maps Xs and Os, whitespaceRemover strips/validates lines, and parseFile handles header parsing, row validation, and error reporting. Errors.h/cpp centralizes error output. Tests.cpp supports quick checks during iteration. 

## TODOs for HW1

### Implement `parseHeader(std::istream&, int& H, int& W)`
- Skip leading blank lines.
- Parse exactly two integers on the first non-blank line and set `H` and `W`.
- On failure, throw `ParserError("Invalid or missing header", headerLineIdx0Based)`.

### Finish `parseFile(...)` main loop
- Read exactly `height` data lines.  
- For each non-blank line:
  - Call `whitespaceRemover(line, width, lineIdx)`.
  - Push result to `grid2D`.
  - Append to `grid1D`.
- If fewer than `height` rows by EOF → throw `ParserError("Invalid column height", offendingLineIdx)`.
- If more than `height` non-blank rows → throw at that extra row’s line index.
- Allow trailing completely blank lines after the grid.

### Error line indexing
- Always throw with **0-based** file line indices.
- `errors.cpp` will convert to **1-based** for messages and exit codes.

### Tests
- Add negative tests for `convertCellChars` (e.g., `'0'` or `'Z'` should throw).
- Add `whitespaceRemover` tests (valid row vs wrong width).
- Optionally add a small `parseHeader` test using `std::istringstream`.

### Small polish
- In `parser.cpp`, remove `#include <sstream>` if it ends up unused.
