#ifndef YARP_DIAGNOSTIC_H
#define YARP_DIAGNOSTIC_H

#include "yarp/defines.h"
#include "yarp/util/yp_list.h"

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// This struct represents a diagnostic found during parsing.
typedef struct {
    yp_list_node_t node;
    const uint8_t *start;
    const uint8_t *end;
    const char *message;
} yp_diagnostic_t;

typedef enum {
    YP_ERR_ALIAS_ARGUMENT,
    YP_ERR_AMPAMPEQ_MULTI_ASSIGN,
    YP_ERR_ARGUMENT_AFTER_BLOCK,
    YP_ERR_ARGUMENT_BARE_HASH,
    YP_ERR_ARGUMENT_BLOCK_MULTI,
    YP_ERR_ARGUMENT_FORMAL_CLASS,
    YP_ERR_ARGUMENT_FORMAL_CONSTANT,
    YP_ERR_ARGUMENT_FORMAL_GLOBAL,
    YP_ERR_ARGUMENT_FORMAL_IVAR,
    YP_ERR_ARGUMENT_NO_FORWARDING_AMP,
    YP_ERR_ARGUMENT_NO_FORWARDING_ELLIPSES,
    YP_ERR_ARGUMENT_NO_FORWARDING_STAR,
    YP_ERR_ARGUMENT_SPLAT_AFTER_ASSOC_SPLAT,
    YP_ERR_ARGUMENT_SPLAT_AFTER_SPLAT,
    YP_ERR_ARGUMENT_TERM_PAREN,
    YP_ERR_ARRAY_ELEMENT,
    YP_ERR_ARRAY_EXPRESSION,
    YP_ERR_ARRAY_EXPRESSION_AFTER_STAR,
    YP_ERR_ARRAY_SEPARATOR,
    YP_ERR_ARRAY_TERM,
    YP_ERR_BEGIN_LONELY_ELSE,
    YP_ERR_BEGIN_TERM,
    YP_ERR_BEGIN_UPCASE_BRACE,
    YP_ERR_BEGIN_UPCASE_TERM,
    YP_ERR_BLOCK_PARAM_LOCAL_VARIABLE,
    YP_ERR_BLOCK_PARAM_PIPE_TERM,
    YP_ERR_BLOCK_TERM_BRACE,
    YP_ERR_BLOCK_TERM_END,
    YP_ERR_CANNOT_PARSE_EXPRESSION,
    YP_ERR_CANNOT_PARSE_STRING_PART,
    YP_ERR_CASE_EXPRESSION_AFTER_CASE,
    YP_ERR_CASE_EXPRESSION_AFTER_WHEN,
    YP_ERR_CASE_LONELY_ELSE,
    YP_ERR_CASE_TERM,
    YP_ERR_CLASS_IN_METHOD,
    YP_ERR_CLASS_NAME,
    YP_ERR_CLASS_SUPERCLASS,
    YP_ERR_CLASS_TERM,
    YP_ERR_CONDITIONAL_ELSIF_PREDICATE,
    YP_ERR_CONDITIONAL_IF_PREDICATE,
    YP_ERR_CONDITIONAL_TERM,
    YP_ERR_CONDITIONAL_TERM_ELSE,
    YP_ERR_CONDITIONAL_UNLESS_PREDICATE,
    YP_ERR_CONDITIONAL_UNTIL_PREDICATE,
    YP_ERR_CONDITIONAL_WHILE_PREDICATE,
    YP_ERR_CONSTANT_PATH_COLON_COLON_CONSTANT,
    YP_ERR_DEF_ENDLESS,
    YP_ERR_DEF_ENDLESS_SETTER,
    YP_ERR_DEF_NAME,
    YP_ERR_DEF_NAME_AFTER_RECEIVER,
    YP_ERR_DEF_PARAMS_TERM,
    YP_ERR_DEF_PARAMS_TERM_PAREN,
    YP_ERR_DEF_RECEIVER,
    YP_ERR_DEF_RECEIVER_TERM,
    YP_ERR_DEF_TERM,
    YP_ERR_DEFINED_EXPRESSION,
    YP_ERR_EMBDOC_TERM,
    YP_ERR_EMBEXPR_END,
    YP_ERR_EMBVAR_INVALID,
    YP_ERR_END_UPCASE_BRACE,
    YP_ERR_END_UPCASE_TERM,
    YP_ERR_ESCAPE_INVALID_CONTROL,
    YP_ERR_ESCAPE_INVALID_CONTROL_REPEAT,
    YP_ERR_ESCAPE_INVALID_HEXADECIMAL,
    YP_ERR_ESCAPE_INVALID_META,
    YP_ERR_ESCAPE_INVALID_META_REPEAT,
    YP_ERR_ESCAPE_INVALID_UNICODE,
    YP_ERR_ESCAPE_INVALID_UNICODE_CM_FLAGS,
    YP_ERR_ESCAPE_INVALID_UNICODE_LITERAL,
    YP_ERR_ESCAPE_INVALID_UNICODE_LONG,
    YP_ERR_ESCAPE_INVALID_UNICODE_TERM,
    YP_ERR_EXPECT_ARGUMENT,
    YP_ERR_EXPECT_EOL_AFTER_STATEMENT,
    YP_ERR_EXPECT_EXPRESSION_AFTER_AMPAMPEQ,
    YP_ERR_EXPECT_EXPRESSION_AFTER_PIPEPIPEEQ,
    YP_ERR_EXPECT_EXPRESSION_AFTER_COMMA,
    YP_ERR_EXPECT_EXPRESSION_AFTER_EQUAL,
    YP_ERR_EXPECT_EXPRESSION_AFTER_LESS_LESS,
    YP_ERR_EXPECT_EXPRESSION_AFTER_LPAREN,
    YP_ERR_EXPECT_EXPRESSION_AFTER_QUESTION,
    YP_ERR_EXPECT_EXPRESSION_AFTER_OPERATOR,
    YP_ERR_EXPECT_EXPRESSION_AFTER_SPLAT,
    YP_ERR_EXPECT_EXPRESSION_AFTER_SPLAT_HASH,
    YP_ERR_EXPECT_EXPRESSION_AFTER_STAR,
    YP_ERR_EXPECT_IDENT_REQ_PARAMETER,
    YP_ERR_EXPECT_LPAREN_REQ_PARAMETER,
    YP_ERR_EXPECT_RBRACKET,
    YP_ERR_EXPECT_RPAREN,
    YP_ERR_EXPECT_RPAREN_AFTER_MULTI,
    YP_ERR_EXPECT_RPAREN_REQ_PARAMETER,
    YP_ERR_EXPECT_STRING_CONTENT,
    YP_ERR_EXPECT_WHEN_DELIMITER,
    YP_ERR_EXPRESSION_BARE_HASH,
    YP_ERR_FOR_COLLECTION,
    YP_ERR_FOR_IN,
    YP_ERR_FOR_INDEX,
    YP_ERR_FOR_TERM,
    YP_ERR_HASH_EXPRESSION_AFTER_LABEL,
    YP_ERR_HASH_KEY,
    YP_ERR_HASH_ROCKET,
    YP_ERR_HASH_TERM,
    YP_ERR_HASH_VALUE,
    YP_ERR_HEREDOC_TERM,
    YP_ERR_INCOMPLETE_QUESTION_MARK,
    YP_ERR_INCOMPLETE_VARIABLE_CLASS,
    YP_ERR_INCOMPLETE_VARIABLE_INSTANCE,
    YP_ERR_INVALID_ENCODING_MAGIC_COMMENT,
    YP_ERR_INVALID_FLOAT_EXPONENT,
    YP_ERR_INVALID_NUMBER_BINARY,
    YP_ERR_INVALID_NUMBER_DECIMAL,
    YP_ERR_INVALID_NUMBER_HEXADECIMAL,
    YP_ERR_INVALID_NUMBER_OCTAL,
    YP_ERR_INVALID_PERCENT,
    YP_ERR_INVALID_TOKEN,
    YP_ERR_INVALID_VARIABLE_GLOBAL,
    YP_ERR_LAMBDA_OPEN,
    YP_ERR_LAMBDA_TERM_BRACE,
    YP_ERR_LAMBDA_TERM_END,
    YP_ERR_LIST_I_LOWER_ELEMENT,
    YP_ERR_LIST_I_LOWER_TERM,
    YP_ERR_LIST_I_UPPER_ELEMENT,
    YP_ERR_LIST_I_UPPER_TERM,
    YP_ERR_LIST_W_LOWER_ELEMENT,
    YP_ERR_LIST_W_LOWER_TERM,
    YP_ERR_LIST_W_UPPER_ELEMENT,
    YP_ERR_LIST_W_UPPER_TERM,
    YP_ERR_MALLOC_FAILED,
    YP_ERR_MODULE_IN_METHOD,
    YP_ERR_MODULE_NAME,
    YP_ERR_MODULE_TERM,
    YP_ERR_MULTI_ASSIGN_MULTI_SPLATS,
    YP_ERR_NOT_EXPRESSION,
    YP_ERR_NUMBER_LITERAL_UNDERSCORE,
    YP_ERR_OPERATOR_MULTI_ASSIGN,
    YP_ERR_OPERATOR_WRITE_BLOCK,
    YP_ERR_PARAMETER_ASSOC_SPLAT_MULTI,
    YP_ERR_PARAMETER_BLOCK_MULTI,
    YP_ERR_PARAMETER_NAME_REPEAT,
    YP_ERR_PARAMETER_NO_DEFAULT,
    YP_ERR_PARAMETER_NO_DEFAULT_KW,
    YP_ERR_PARAMETER_NUMBERED_RESERVED,
    YP_ERR_PARAMETER_ORDER,
    YP_ERR_PARAMETER_SPLAT_MULTI,
    YP_ERR_PARAMETER_STAR,
    YP_ERR_PARAMETER_WILD_LOOSE_COMMA,
    YP_ERR_PATTERN_EXPRESSION_AFTER_BRACKET,
    YP_ERR_PATTERN_EXPRESSION_AFTER_HROCKET,
    YP_ERR_PATTERN_EXPRESSION_AFTER_COMMA,
    YP_ERR_PATTERN_EXPRESSION_AFTER_IN,
    YP_ERR_PATTERN_EXPRESSION_AFTER_KEY,
    YP_ERR_PATTERN_EXPRESSION_AFTER_PAREN,
    YP_ERR_PATTERN_EXPRESSION_AFTER_PIN,
    YP_ERR_PATTERN_EXPRESSION_AFTER_PIPE,
    YP_ERR_PATTERN_EXPRESSION_AFTER_RANGE,
    YP_ERR_PATTERN_HASH_KEY,
    YP_ERR_PATTERN_HASH_KEY_LABEL,
    YP_ERR_PATTERN_IDENT_AFTER_HROCKET,
    YP_ERR_PATTERN_LABEL_AFTER_COMMA,
    YP_ERR_PATTERN_REST,
    YP_ERR_PATTERN_TERM_BRACE,
    YP_ERR_PATTERN_TERM_BRACKET,
    YP_ERR_PATTERN_TERM_PAREN,
    YP_ERR_PIPEPIPEEQ_MULTI_ASSIGN,
    YP_ERR_REGEXP_TERM,
    YP_ERR_RESCUE_EXPRESSION,
    YP_ERR_RESCUE_MODIFIER_VALUE,
    YP_ERR_RESCUE_TERM,
    YP_ERR_RESCUE_VARIABLE,
    YP_ERR_RETURN_INVALID,
    YP_ERR_STRING_CONCATENATION,
    YP_ERR_STRING_INTERPOLATED_TERM,
    YP_ERR_STRING_LITERAL_TERM,
    YP_ERR_SYMBOL_INVALID,
    YP_ERR_SYMBOL_TERM_DYNAMIC,
    YP_ERR_SYMBOL_TERM_INTERPOLATED,
    YP_ERR_TERNARY_COLON,
    YP_ERR_TERNARY_EXPRESSION_FALSE,
    YP_ERR_TERNARY_EXPRESSION_TRUE,
    YP_ERR_UNDEF_ARGUMENT,
    YP_ERR_UNARY_RECEIVER_BANG,
    YP_ERR_UNARY_RECEIVER_MINUS,
    YP_ERR_UNARY_RECEIVER_PLUS,
    YP_ERR_UNARY_RECEIVER_TILDE,
    YP_ERR_UNTIL_TERM,
    YP_ERR_WHILE_TERM,
    YP_ERR_WRITE_TARGET_READONLY,
    YP_ERR_WRITE_TARGET_UNEXPECTED,
    YP_ERR_XSTRING_TERM,
    YP_WARN_AMBIGUOUS_FIRST_ARGUMENT_MINUS,
    YP_WARN_AMBIGUOUS_FIRST_ARGUMENT_PLUS,
    YP_WARN_AMBIGUOUS_PREFIX_STAR,
    YP_WARN_AMBIGUOUS_SLASH,
    /* This must be the last member. */
    YP_DIAGNOSTIC_ID_LEN,
} yp_diagnostic_id_t;

// Append a diagnostic to the given list of diagnostics.
bool yp_diagnostic_list_append(yp_list_t *list, const uint8_t *start, const uint8_t *end, yp_diagnostic_id_t diag_id);

// Deallocate the internal state of the given diagnostic list.
void yp_diagnostic_list_free(yp_list_t *list);

#endif
