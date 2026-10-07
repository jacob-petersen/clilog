/**
 * 
 * @brief This header define the core  class which handles validation and passes data between 
 * the UI and persistence layers. Also defines some helper data structures.
 * 
 * 
 * Keep it simple, stupid. 
 */

#pragma once

#include <optional>

#include "clilog/log_entry.hpp"
#include "clilog/log_store.hpp"

namespace clilog {

/**
 * @brief This is the "Core" class of the whole program. It makes up the "Logic" layer of the 
 * software architecture. It handles all logic, including validation and passing messages to 
 * and from the UI layer and the Persistence layer.
 */
class LoggingCore {

    private:
    clilog::LogStore log_store_;

    public:
    LoggingCore();

    /**
     * @brief Takes a `clilog::LogEntryDraft` and validates it. If it is valid, creates a 
     * `clilog::LogEntry` and passes it to the `clilog::LogStore`.
     * 
     * @param log_entry_draft a `clilog::LogEntryDraft`.
     * @returns Nothing for now. 
     */
    void process_log_entry_draft(clilog::LogEntryDraft log_entry_draft);

    /**
     * @brief Filters the passed character, returning it back if it is allowed. 
     * Valid characters are `A-Z`, `0-9`, `-`, `.`.
     * `a-z` are also valid but will be capitalized before being returned. 
     * @param c the typed character.
     * @returns `std::optional<char>`, which contains the char to be added, or `std::nullopt`
     * if the char was invalid.
     */
    std::optional<char> filter_callsign_keystroke(char c);

    /**
     * @brief Filters the passed character, returning it back if it is allowed.
     * Valid characters are `0-9` and `.`.
     * @param c the typed character.
     * @returns `std::optional<char>`, which contains the char to be added, or `std::nullopt`
     * if the char was invalid.
     */
    std::optional<char> filter_freq_keystroke(char c);
};

}
