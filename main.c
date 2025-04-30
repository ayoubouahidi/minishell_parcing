#include "parser.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av) {
    // while (1) {
    //     char *line = readline("minishell$ ");
    //     if (!line)
    //         break;
    //     if (*line)
    //         add_history(line);

    //     t_command *cmd = parse_line(line);
    //     t_command *tmp = cmd;

    //     while (tmp) {
    //         if (tmp->args && tmp->args[0]) {
    //             if (is_builtin(tmp->args[0]))
    //                 execute_builtin(tmp);
    //             // else
    //             //     execute_external(tmp);
    //         }
    //         tmp = tmp->next;
    //     }

    //     free_commands(cmd);
    //     free(line);
    // }
    // return 0;
	parcer(ac, av);
}





// // // to see 
// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <ctype.h>

// // Define whitespace characters
// #define WHITESPACE " \t\n\r\f\v"

// typedef enum e_token_type {
//     TOKEN_WORD,
//     TOKEN_PIPE,
//     TOKEN_REDIRECT_IN,    // <
//     TOKEN_REDIRECT_OUT,   // >
//     TOKEN_REDIRECT_APPEND, // >>
//     TOKEN_REDIRECT_HEREDOC, // <<
//     TOKEN_EOF
// } t_token_type;

// typedef struct s_token {
//     t_token_type type;
//     char *value;
// } t_token;

// // Helper function to check if character is a special shell character
// static bool is_special_char(char c) {
//     return (c == '|' || c == '<' || c == '>' || c == ';' || c == '&');
// }

// // Create a new token
// static t_token *create_token(t_token_type type, char *value) {
//     t_token *token = malloc(sizeof(t_token));
//     if (!token) return NULL;
    
//     token->type = type;
//     token->value = value ? strdup(value) : NULL;
//     return token;
// }

// // Skip whitespace characters
// static void skip_whitespace(char **input) {
//     while (**input && strchr(WHITESPACE, **input)) {
//         (*input)++;
//     }
// }

// // Handle quoted strings (both single and double)
// static char *handle_quotes(char **input, char quote_type) {
//     (*input)++; // Skip opening quote
//     char *start = *input;
//     size_t len = 0;
    
//     while (**input && **input != quote_type) {
//         if (**input == '\\' && quote_type == '"') {
//             (*input)++; // Skip escape character
//             if (**input) {
//                 len++;
//                 (*input)++;
//             }
//         } else {
//             len++;
//             (*input)++;
//         }
//     }
    
//     char *value = strndup(start, len);
//     if (**input == quote_type) (*input)++; // Skip closing quote
//     return value;
// }

// // Handle redirection tokens (>, >>, <, <<)
// static t_token *handle_redirect(char **input) {
//     char first = **input;
//     (*input)++;
    
//     if (**input == first) { // Check for >> or <<
//         (*input)++;
//         if (first == '>') return create_token(TOKEN_REDIRECT_APPEND, NULL);
//         else return create_token(TOKEN_REDIRECT_HEREDOC, NULL);
//     } else {
//         if (first == '>') return create_token(TOKEN_REDIRECT_OUT, NULL);
//         else return create_token(TOKEN_REDIRECT_IN, NULL);
//     }
// }

// // Main tokenization function
// t_token **tokenize(char *input) {
//     t_token **tokens = malloc(100 * sizeof(t_token *));
//     size_t token_count = 0;
    
//     while (*input) {
//         skip_whitespace(&input);
//         if (!*input) break;
        
//         if (*input == '\'' || *input == '"') {
//             char quote_type = *input;
//             char *value = handle_quotes(&input, quote_type);
//             tokens[token_count++] = create_token(TOKEN_WORD, value);
//             free(value);
//         }
//         else if (*input == '|') {
//             input++;
//             tokens[token_count++] = create_token(TOKEN_PIPE, NULL);
//         }
//         else if (*input == '<' || *input == '>') {
//             tokens[token_count++] = handle_redirect(&input);
//         }
//         else {
//             char *start = input;
//             while (*input && !strchr(WHITESPACE, *input) && !is_special_char(*input)) {
//                 input++;
//             }
//             char *value = strndup(start, input - start);
//             tokens[token_count++] = create_token(TOKEN_WORD, value);
//             free(value);
//         }
//     }
    
//     tokens[token_count] = create_token(TOKEN_EOF, NULL);
//     return tokens;
// 	}

// // Example usage:
// void print_tokens(t_token **tokens) {
//     for (int i = 0; tokens[i]->type != TOKEN_EOF; i++) {
//         const char *type_str;
//         switch (tokens[i]->type) {
//             case TOKEN_WORD: type_str = "WORD"; break;
//             case TOKEN_PIPE: type_str = "PIPE"; break;
//             case TOKEN_REDIRECT_IN: type_str = "REDIR_IN"; break;
//             case TOKEN_REDIRECT_OUT: type_str = "REDIR_OUT"; break;
//             case TOKEN_REDIRECT_APPEND: type_str = "REDIR_APPEND"; break;
//             case TOKEN_REDIRECT_HEREDOC: type_str = "REDIR_HEREDOC"; break;
//             default: type_str = "UNKNOWN";
//         }
//         printf("Token %d: Type=%s, Value='%s'\n", 
//                i, type_str, tokens[i]->value ? tokens[i]->value : "NULL");
//     }
// }

// int main() {
//     char *input = "ls -la | grep \"hello world\" > out.txt << EOF";
//     t_token **tokens = tokenize(input);
//     print_tokens(tokens);
    
//     // Free tokens
//     for (int i = 0; tokens[i]->type != TOKEN_EOF; i++) {
//         free(tokens[i]->value);
//         free(tokens[i]);
//     }
//     free(tokens);
//     return 0;
// }

// #include "include/lexer.h"
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdio.h>


// lexer_T* init_lexer(char* contents)
// {
//     lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
//     lexer->contents = contents;
//     lexer->i = 0;
//     lexer->c = contents[lexer->i];

//     return lexer;
// }

// void lexer_advance(lexer_T* lexer)
// {
//     if (lexer->c != '\0' && lexer->i < strlen(lexer->contents))
//     {
//         lexer->i += 1;
//         lexer->c = lexer->contents[lexer->i];
//     }
// }

// void lexer_skip_whitespace(lexer_T* lexer)
// {
//     while (lexer->c == ' ' || lexer->c == 10)
//     {
//         lexer_advance(lexer);
//     }
// }

// token_T* lexer_get_next_token(lexer_T* lexer)
// {
//     while (lexer->c != '\0' && lexer->i < strlen(lexer->contents))
//     {
//         if (lexer->c == ' ' || lexer->c == 10)
//             lexer_skip_whitespace(lexer);

//         if (isalnum(lexer->c))
//             return lexer_collect_id(lexer);

//         if (lexer->c == '"')
//             return lexer_collect_string(lexer);

//         switch (lexer->c)
//         {
//             case '=': return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer))); break;
//             case ';': return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_string(lexer))); break;
//             case '(': return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer))); break;
//             case ')': return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer))); break;
//             case '{': return lexer_advance_with_token(lexer, init_token(TOKEN_LBRACE, lexer_get_current_char_as_string(lexer))); break;
//             case '}': return lexer_advance_with_token(lexer, init_token(TOKEN_RBRACE, lexer_get_current_char_as_string(lexer))); break;
//             case ',': return lexer_advance_with_token(lexer, init_token(TOKEN_COMMA, lexer_get_current_char_as_string(lexer))); break;
//         }
//     }

//     return init_token(TOKEN_EOF, "\0");
// }

// token_T* lexer_collect_string(lexer_T* lexer)
// {
//     lexer_advance(lexer);

//     char* value = calloc(1, sizeof(char));
//     value[0] = '\0';

//     while (lexer->c != '"')
//     {
//         char* s = lexer_get_current_char_as_string(lexer);
//         value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
//         strcat(value, s);

//         lexer_advance(lexer);
//     }

//     lexer_advance(lexer);

//     return init_token(TOKEN_STRING, value);
// }

// token_T* lexer_collect_id(lexer_T* lexer)
// {
//     char* value = calloc(1, sizeof(char));
//     value[0] = '\0';

//     while (isalnum(lexer->c))
//     {
//         char* s = lexer_get_current_char_as_string(lexer);
//         value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
//         strcat(value, s);

//         lexer_advance(lexer);
//     }

//     return init_token(TOKEN_ID, value);
// }

// token_T* lexer_advance_with_token(lexer_T* lexer, token_T* token)
// {
//     lexer_advance(lexer);

//     return token;
// }

// char* lexer_get_current_char_as_string(lexer_T* lexer)
// {
//     char* str = calloc(2, sizeof(char));
//     str[0] = lexer->c;
//     str[1] = '\0';

//     return str;
// }