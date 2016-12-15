// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file binary.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_BINARY_TAB_HH_INCLUDED
# define YY_YY_BINARY_TAB_HH_INCLUDED
// //                    "%code requires" blocks.
#line 5 "binary.yy" // lalr1.cc:372

	#include <string>
	#include <iostream>
  	#include <list>
  	#include "Node.h"

#line 51 "binary.tab.hh" // lalr1.cc:372


# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"


#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 127 "binary.tab.hh" // lalr1.cc:372



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // S
      // block
      // chunk
      // chunk_layer
      // laststat_layer
      // stat
      // elseif_layer
      // laststat
      // funcname
      // funcname_layer
      // varlist
      // varlist_layer
      // var
      // namelist
      // namelist_layer
      // explist
      // explist_layer
      // exp
      // term
      // exp_layer
      // Number
      // Name
      // String
      // prefixexp
      // functioncall
      // args
      // function
      // funcbody
      // parlist
      // tableconstructor
      // fieldlist
      // fieldlist_layer
      // field
      // fieldsep
      char dummy1[sizeof(Node)];

      // AND
      // BREAK
      // DO
      // ELSE
      // ELSEIF
      // end
      // FALSE
      // FOR
      // FUNCTION
      // IF
      // IN
      // LOCAL
      // NIL
      // NOT
      // OR
      // REPEAT
      // RETURN
      // THEN
      // TRUE
      // UNTIL
      // WHILE
      // PLUS
      // MINUS
      // MULTIPLY
      // DEVIDE
      // PERCENT
      // CARET
      // HASHTAG
      // EQUALTO
      // TILDEEQUAL
      // LESSOREQUAL
      // GREATEROREQUAL
      // LESSTHAN
      // GREATERTHAN
      // EQUAL
      // LEFTPARENTHESES
      // RIGHTPARENTHESES
      // LEFTBRACES
      // RIGHTBRACES
      // LEFTBRACKET
      // RIGHTBRACKET
      // SEMICOLON
      // COLON
      // COMMA
      // DOT
      // DOTDOT
      // DOTDOTDOT
      // INTEGER
      // DECIMAL
      // POWEROF
      // HEXADECIMAL
      // STRING
      // NAME
      char dummy2[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        AND = 258,
        BREAK = 259,
        DO = 260,
        ELSE = 261,
        ELSEIF = 262,
        end = 263,
        FALSE = 264,
        FOR = 265,
        FUNCTION = 266,
        IF = 267,
        IN = 268,
        LOCAL = 269,
        NIL = 270,
        NOT = 271,
        OR = 272,
        REPEAT = 273,
        RETURN = 274,
        THEN = 275,
        TRUE = 276,
        UNTIL = 277,
        WHILE = 278,
        PLUS = 279,
        MINUS = 280,
        MULTIPLY = 281,
        DEVIDE = 282,
        PERCENT = 283,
        CARET = 284,
        HASHTAG = 285,
        EQUALTO = 286,
        TILDEEQUAL = 287,
        LESSOREQUAL = 288,
        GREATEROREQUAL = 289,
        LESSTHAN = 290,
        GREATERTHAN = 291,
        EQUAL = 292,
        LEFTPARENTHESES = 293,
        RIGHTPARENTHESES = 294,
        LEFTBRACES = 295,
        RIGHTBRACES = 296,
        LEFTBRACKET = 297,
        RIGHTBRACKET = 298,
        SEMICOLON = 299,
        COLON = 300,
        COMMA = 301,
        DOT = 302,
        DOTDOT = 303,
        DOTDOTDOT = 304,
        INTEGER = 305,
        DECIMAL = 306,
        POWEROF = 307,
        HEXADECIMAL = 308,
        STRING = 309,
        NAME = 310
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t);

  basic_symbol (typename Base::kind_type t, const Node v);

  basic_symbol (typename Base::kind_type t, const std::string v);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      ~basic_symbol ();

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END ();

    static inline
    symbol_type
    make_AND (const std::string& v);

    static inline
    symbol_type
    make_BREAK (const std::string& v);

    static inline
    symbol_type
    make_DO (const std::string& v);

    static inline
    symbol_type
    make_ELSE (const std::string& v);

    static inline
    symbol_type
    make_ELSEIF (const std::string& v);

    static inline
    symbol_type
    make_end (const std::string& v);

    static inline
    symbol_type
    make_FALSE (const std::string& v);

    static inline
    symbol_type
    make_FOR (const std::string& v);

    static inline
    symbol_type
    make_FUNCTION (const std::string& v);

    static inline
    symbol_type
    make_IF (const std::string& v);

    static inline
    symbol_type
    make_IN (const std::string& v);

    static inline
    symbol_type
    make_LOCAL (const std::string& v);

    static inline
    symbol_type
    make_NIL (const std::string& v);

    static inline
    symbol_type
    make_NOT (const std::string& v);

    static inline
    symbol_type
    make_OR (const std::string& v);

    static inline
    symbol_type
    make_REPEAT (const std::string& v);

    static inline
    symbol_type
    make_RETURN (const std::string& v);

    static inline
    symbol_type
    make_THEN (const std::string& v);

    static inline
    symbol_type
    make_TRUE (const std::string& v);

    static inline
    symbol_type
    make_UNTIL (const std::string& v);

    static inline
    symbol_type
    make_WHILE (const std::string& v);

    static inline
    symbol_type
    make_PLUS (const std::string& v);

    static inline
    symbol_type
    make_MINUS (const std::string& v);

    static inline
    symbol_type
    make_MULTIPLY (const std::string& v);

    static inline
    symbol_type
    make_DEVIDE (const std::string& v);

    static inline
    symbol_type
    make_PERCENT (const std::string& v);

    static inline
    symbol_type
    make_CARET (const std::string& v);

    static inline
    symbol_type
    make_HASHTAG (const std::string& v);

    static inline
    symbol_type
    make_EQUALTO (const std::string& v);

    static inline
    symbol_type
    make_TILDEEQUAL (const std::string& v);

    static inline
    symbol_type
    make_LESSOREQUAL (const std::string& v);

    static inline
    symbol_type
    make_GREATEROREQUAL (const std::string& v);

    static inline
    symbol_type
    make_LESSTHAN (const std::string& v);

    static inline
    symbol_type
    make_GREATERTHAN (const std::string& v);

    static inline
    symbol_type
    make_EQUAL (const std::string& v);

    static inline
    symbol_type
    make_LEFTPARENTHESES (const std::string& v);

    static inline
    symbol_type
    make_RIGHTPARENTHESES (const std::string& v);

    static inline
    symbol_type
    make_LEFTBRACES (const std::string& v);

    static inline
    symbol_type
    make_RIGHTBRACES (const std::string& v);

    static inline
    symbol_type
    make_LEFTBRACKET (const std::string& v);

    static inline
    symbol_type
    make_RIGHTBRACKET (const std::string& v);

    static inline
    symbol_type
    make_SEMICOLON (const std::string& v);

    static inline
    symbol_type
    make_COLON (const std::string& v);

    static inline
    symbol_type
    make_COMMA (const std::string& v);

    static inline
    symbol_type
    make_DOT (const std::string& v);

    static inline
    symbol_type
    make_DOTDOT (const std::string& v);

    static inline
    symbol_type
    make_DOTDOTDOT (const std::string& v);

    static inline
    symbol_type
    make_INTEGER (const std::string& v);

    static inline
    symbol_type
    make_DECIMAL (const std::string& v);

    static inline
    symbol_type
    make_POWEROF (const std::string& v);

    static inline
    symbol_type
    make_HEXADECIMAL (const std::string& v);

    static inline
    symbol_type
    make_STRING (const std::string& v);

    static inline
    symbol_type
    make_NAME (const std::string& v);


    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 461,     ///< Last index in yytable_.
      yynnts_ = 35,  ///< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 62, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 56  ///< Number of tokens.
    };


  };

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    const unsigned int user_token_number_max_ = 310;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
    {
      case 57: // S
      case 58: // block
      case 59: // chunk
      case 60: // chunk_layer
      case 61: // laststat_layer
      case 62: // stat
      case 63: // elseif_layer
      case 64: // laststat
      case 65: // funcname
      case 66: // funcname_layer
      case 67: // varlist
      case 68: // varlist_layer
      case 69: // var
      case 70: // namelist
      case 71: // namelist_layer
      case 72: // explist
      case 73: // explist_layer
      case 74: // exp
      case 75: // term
      case 76: // exp_layer
      case 77: // Number
      case 78: // Name
      case 79: // String
      case 80: // prefixexp
      case 81: // functioncall
      case 82: // args
      case 83: // function
      case 84: // funcbody
      case 85: // parlist
      case 86: // tableconstructor
      case 87: // fieldlist
      case 88: // fieldlist_layer
      case 89: // field
      case 90: // fieldsep
        value.copy< Node > (other.value);
        break;

      case 3: // AND
      case 4: // BREAK
      case 5: // DO
      case 6: // ELSE
      case 7: // ELSEIF
      case 8: // end
      case 9: // FALSE
      case 10: // FOR
      case 11: // FUNCTION
      case 12: // IF
      case 13: // IN
      case 14: // LOCAL
      case 15: // NIL
      case 16: // NOT
      case 17: // OR
      case 18: // REPEAT
      case 19: // RETURN
      case 20: // THEN
      case 21: // TRUE
      case 22: // UNTIL
      case 23: // WHILE
      case 24: // PLUS
      case 25: // MINUS
      case 26: // MULTIPLY
      case 27: // DEVIDE
      case 28: // PERCENT
      case 29: // CARET
      case 30: // HASHTAG
      case 31: // EQUALTO
      case 32: // TILDEEQUAL
      case 33: // LESSOREQUAL
      case 34: // GREATEROREQUAL
      case 35: // LESSTHAN
      case 36: // GREATERTHAN
      case 37: // EQUAL
      case 38: // LEFTPARENTHESES
      case 39: // RIGHTPARENTHESES
      case 40: // LEFTBRACES
      case 41: // RIGHTBRACES
      case 42: // LEFTBRACKET
      case 43: // RIGHTBRACKET
      case 44: // SEMICOLON
      case 45: // COLON
      case 46: // COMMA
      case 47: // DOT
      case 48: // DOTDOT
      case 49: // DOTDOTDOT
      case 50: // INTEGER
      case 51: // DECIMAL
      case 52: // POWEROF
      case 53: // HEXADECIMAL
      case 54: // STRING
      case 55: // NAME
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
    {
      case 57: // S
      case 58: // block
      case 59: // chunk
      case 60: // chunk_layer
      case 61: // laststat_layer
      case 62: // stat
      case 63: // elseif_layer
      case 64: // laststat
      case 65: // funcname
      case 66: // funcname_layer
      case 67: // varlist
      case 68: // varlist_layer
      case 69: // var
      case 70: // namelist
      case 71: // namelist_layer
      case 72: // explist
      case 73: // explist_layer
      case 74: // exp
      case 75: // term
      case 76: // exp_layer
      case 77: // Number
      case 78: // Name
      case 79: // String
      case 80: // prefixexp
      case 81: // functioncall
      case 82: // args
      case 83: // function
      case 84: // funcbody
      case 85: // parlist
      case 86: // tableconstructor
      case 87: // fieldlist
      case 88: // fieldlist_layer
      case 89: // field
      case 90: // fieldsep
        value.copy< Node > (v);
        break;

      case 3: // AND
      case 4: // BREAK
      case 5: // DO
      case 6: // ELSE
      case 7: // ELSEIF
      case 8: // end
      case 9: // FALSE
      case 10: // FOR
      case 11: // FUNCTION
      case 12: // IF
      case 13: // IN
      case 14: // LOCAL
      case 15: // NIL
      case 16: // NOT
      case 17: // OR
      case 18: // REPEAT
      case 19: // RETURN
      case 20: // THEN
      case 21: // TRUE
      case 22: // UNTIL
      case 23: // WHILE
      case 24: // PLUS
      case 25: // MINUS
      case 26: // MULTIPLY
      case 27: // DEVIDE
      case 28: // PERCENT
      case 29: // CARET
      case 30: // HASHTAG
      case 31: // EQUALTO
      case 32: // TILDEEQUAL
      case 33: // LESSOREQUAL
      case 34: // GREATEROREQUAL
      case 35: // LESSTHAN
      case 36: // GREATERTHAN
      case 37: // EQUAL
      case 38: // LEFTPARENTHESES
      case 39: // RIGHTPARENTHESES
      case 40: // LEFTBRACES
      case 41: // RIGHTBRACES
      case 42: // LEFTBRACKET
      case 43: // RIGHTBRACKET
      case 44: // SEMICOLON
      case 45: // COLON
      case 46: // COMMA
      case 47: // DOT
      case 48: // DOTDOT
      case 49: // DOTDOTDOT
      case 50: // INTEGER
      case 51: // DECIMAL
      case 52: // POWEROF
      case 53: // HEXADECIMAL
      case 54: // STRING
      case 55: // NAME
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Node v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 57: // S
      case 58: // block
      case 59: // chunk
      case 60: // chunk_layer
      case 61: // laststat_layer
      case 62: // stat
      case 63: // elseif_layer
      case 64: // laststat
      case 65: // funcname
      case 66: // funcname_layer
      case 67: // varlist
      case 68: // varlist_layer
      case 69: // var
      case 70: // namelist
      case 71: // namelist_layer
      case 72: // explist
      case 73: // explist_layer
      case 74: // exp
      case 75: // term
      case 76: // exp_layer
      case 77: // Number
      case 78: // Name
      case 79: // String
      case 80: // prefixexp
      case 81: // functioncall
      case 82: // args
      case 83: // function
      case 84: // funcbody
      case 85: // parlist
      case 86: // tableconstructor
      case 87: // fieldlist
      case 88: // fieldlist_layer
      case 89: // field
      case 90: // fieldsep
        value.template destroy< Node > ();
        break;

      case 3: // AND
      case 4: // BREAK
      case 5: // DO
      case 6: // ELSE
      case 7: // ELSEIF
      case 8: // end
      case 9: // FALSE
      case 10: // FOR
      case 11: // FUNCTION
      case 12: // IF
      case 13: // IN
      case 14: // LOCAL
      case 15: // NIL
      case 16: // NOT
      case 17: // OR
      case 18: // REPEAT
      case 19: // RETURN
      case 20: // THEN
      case 21: // TRUE
      case 22: // UNTIL
      case 23: // WHILE
      case 24: // PLUS
      case 25: // MINUS
      case 26: // MULTIPLY
      case 27: // DEVIDE
      case 28: // PERCENT
      case 29: // CARET
      case 30: // HASHTAG
      case 31: // EQUALTO
      case 32: // TILDEEQUAL
      case 33: // LESSOREQUAL
      case 34: // GREATEROREQUAL
      case 35: // LESSTHAN
      case 36: // GREATERTHAN
      case 37: // EQUAL
      case 38: // LEFTPARENTHESES
      case 39: // RIGHTPARENTHESES
      case 40: // LEFTBRACES
      case 41: // RIGHTBRACES
      case 42: // LEFTBRACKET
      case 43: // RIGHTBRACKET
      case 44: // SEMICOLON
      case 45: // COLON
      case 46: // COMMA
      case 47: // DOT
      case 48: // DOTDOT
      case 49: // DOTDOTDOT
      case 50: // INTEGER
      case 51: // DECIMAL
      case 52: // POWEROF
      case 53: // HEXADECIMAL
      case 54: // STRING
      case 55: // NAME
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 57: // S
      case 58: // block
      case 59: // chunk
      case 60: // chunk_layer
      case 61: // laststat_layer
      case 62: // stat
      case 63: // elseif_layer
      case 64: // laststat
      case 65: // funcname
      case 66: // funcname_layer
      case 67: // varlist
      case 68: // varlist_layer
      case 69: // var
      case 70: // namelist
      case 71: // namelist_layer
      case 72: // explist
      case 73: // explist_layer
      case 74: // exp
      case 75: // term
      case 76: // exp_layer
      case 77: // Number
      case 78: // Name
      case 79: // String
      case 80: // prefixexp
      case 81: // functioncall
      case 82: // args
      case 83: // function
      case 84: // funcbody
      case 85: // parlist
      case 86: // tableconstructor
      case 87: // fieldlist
      case 88: // fieldlist_layer
      case 89: // field
      case 90: // fieldsep
        value.move< Node > (s.value);
        break;

      case 3: // AND
      case 4: // BREAK
      case 5: // DO
      case 6: // ELSE
      case 7: // ELSEIF
      case 8: // end
      case 9: // FALSE
      case 10: // FOR
      case 11: // FUNCTION
      case 12: // IF
      case 13: // IN
      case 14: // LOCAL
      case 15: // NIL
      case 16: // NOT
      case 17: // OR
      case 18: // REPEAT
      case 19: // RETURN
      case 20: // THEN
      case 21: // TRUE
      case 22: // UNTIL
      case 23: // WHILE
      case 24: // PLUS
      case 25: // MINUS
      case 26: // MULTIPLY
      case 27: // DEVIDE
      case 28: // PERCENT
      case 29: // CARET
      case 30: // HASHTAG
      case 31: // EQUALTO
      case 32: // TILDEEQUAL
      case 33: // LESSOREQUAL
      case 34: // GREATEROREQUAL
      case 35: // LESSTHAN
      case 36: // GREATERTHAN
      case 37: // EQUAL
      case 38: // LEFTPARENTHESES
      case 39: // RIGHTPARENTHESES
      case 40: // LEFTBRACES
      case 41: // RIGHTBRACES
      case 42: // LEFTBRACKET
      case 43: // RIGHTBRACKET
      case 44: // SEMICOLON
      case 45: // COLON
      case 46: // COMMA
      case 47: // DOT
      case 48: // DOTDOT
      case 49: // DOTDOTDOT
      case 50: // INTEGER
      case 51: // DECIMAL
      case 52: // POWEROF
      case 53: // HEXADECIMAL
      case 54: // STRING
      case 55: // NAME
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_END ()
  {
    return symbol_type (token::END);
  }

  parser::symbol_type
  parser::make_AND (const std::string& v)
  {
    return symbol_type (token::AND, v);
  }

  parser::symbol_type
  parser::make_BREAK (const std::string& v)
  {
    return symbol_type (token::BREAK, v);
  }

  parser::symbol_type
  parser::make_DO (const std::string& v)
  {
    return symbol_type (token::DO, v);
  }

  parser::symbol_type
  parser::make_ELSE (const std::string& v)
  {
    return symbol_type (token::ELSE, v);
  }

  parser::symbol_type
  parser::make_ELSEIF (const std::string& v)
  {
    return symbol_type (token::ELSEIF, v);
  }

  parser::symbol_type
  parser::make_end (const std::string& v)
  {
    return symbol_type (token::end, v);
  }

  parser::symbol_type
  parser::make_FALSE (const std::string& v)
  {
    return symbol_type (token::FALSE, v);
  }

  parser::symbol_type
  parser::make_FOR (const std::string& v)
  {
    return symbol_type (token::FOR, v);
  }

  parser::symbol_type
  parser::make_FUNCTION (const std::string& v)
  {
    return symbol_type (token::FUNCTION, v);
  }

  parser::symbol_type
  parser::make_IF (const std::string& v)
  {
    return symbol_type (token::IF, v);
  }

  parser::symbol_type
  parser::make_IN (const std::string& v)
  {
    return symbol_type (token::IN, v);
  }

  parser::symbol_type
  parser::make_LOCAL (const std::string& v)
  {
    return symbol_type (token::LOCAL, v);
  }

  parser::symbol_type
  parser::make_NIL (const std::string& v)
  {
    return symbol_type (token::NIL, v);
  }

  parser::symbol_type
  parser::make_NOT (const std::string& v)
  {
    return symbol_type (token::NOT, v);
  }

  parser::symbol_type
  parser::make_OR (const std::string& v)
  {
    return symbol_type (token::OR, v);
  }

  parser::symbol_type
  parser::make_REPEAT (const std::string& v)
  {
    return symbol_type (token::REPEAT, v);
  }

  parser::symbol_type
  parser::make_RETURN (const std::string& v)
  {
    return symbol_type (token::RETURN, v);
  }

  parser::symbol_type
  parser::make_THEN (const std::string& v)
  {
    return symbol_type (token::THEN, v);
  }

  parser::symbol_type
  parser::make_TRUE (const std::string& v)
  {
    return symbol_type (token::TRUE, v);
  }

  parser::symbol_type
  parser::make_UNTIL (const std::string& v)
  {
    return symbol_type (token::UNTIL, v);
  }

  parser::symbol_type
  parser::make_WHILE (const std::string& v)
  {
    return symbol_type (token::WHILE, v);
  }

  parser::symbol_type
  parser::make_PLUS (const std::string& v)
  {
    return symbol_type (token::PLUS, v);
  }

  parser::symbol_type
  parser::make_MINUS (const std::string& v)
  {
    return symbol_type (token::MINUS, v);
  }

  parser::symbol_type
  parser::make_MULTIPLY (const std::string& v)
  {
    return symbol_type (token::MULTIPLY, v);
  }

  parser::symbol_type
  parser::make_DEVIDE (const std::string& v)
  {
    return symbol_type (token::DEVIDE, v);
  }

  parser::symbol_type
  parser::make_PERCENT (const std::string& v)
  {
    return symbol_type (token::PERCENT, v);
  }

  parser::symbol_type
  parser::make_CARET (const std::string& v)
  {
    return symbol_type (token::CARET, v);
  }

  parser::symbol_type
  parser::make_HASHTAG (const std::string& v)
  {
    return symbol_type (token::HASHTAG, v);
  }

  parser::symbol_type
  parser::make_EQUALTO (const std::string& v)
  {
    return symbol_type (token::EQUALTO, v);
  }

  parser::symbol_type
  parser::make_TILDEEQUAL (const std::string& v)
  {
    return symbol_type (token::TILDEEQUAL, v);
  }

  parser::symbol_type
  parser::make_LESSOREQUAL (const std::string& v)
  {
    return symbol_type (token::LESSOREQUAL, v);
  }

  parser::symbol_type
  parser::make_GREATEROREQUAL (const std::string& v)
  {
    return symbol_type (token::GREATEROREQUAL, v);
  }

  parser::symbol_type
  parser::make_LESSTHAN (const std::string& v)
  {
    return symbol_type (token::LESSTHAN, v);
  }

  parser::symbol_type
  parser::make_GREATERTHAN (const std::string& v)
  {
    return symbol_type (token::GREATERTHAN, v);
  }

  parser::symbol_type
  parser::make_EQUAL (const std::string& v)
  {
    return symbol_type (token::EQUAL, v);
  }

  parser::symbol_type
  parser::make_LEFTPARENTHESES (const std::string& v)
  {
    return symbol_type (token::LEFTPARENTHESES, v);
  }

  parser::symbol_type
  parser::make_RIGHTPARENTHESES (const std::string& v)
  {
    return symbol_type (token::RIGHTPARENTHESES, v);
  }

  parser::symbol_type
  parser::make_LEFTBRACES (const std::string& v)
  {
    return symbol_type (token::LEFTBRACES, v);
  }

  parser::symbol_type
  parser::make_RIGHTBRACES (const std::string& v)
  {
    return symbol_type (token::RIGHTBRACES, v);
  }

  parser::symbol_type
  parser::make_LEFTBRACKET (const std::string& v)
  {
    return symbol_type (token::LEFTBRACKET, v);
  }

  parser::symbol_type
  parser::make_RIGHTBRACKET (const std::string& v)
  {
    return symbol_type (token::RIGHTBRACKET, v);
  }

  parser::symbol_type
  parser::make_SEMICOLON (const std::string& v)
  {
    return symbol_type (token::SEMICOLON, v);
  }

  parser::symbol_type
  parser::make_COLON (const std::string& v)
  {
    return symbol_type (token::COLON, v);
  }

  parser::symbol_type
  parser::make_COMMA (const std::string& v)
  {
    return symbol_type (token::COMMA, v);
  }

  parser::symbol_type
  parser::make_DOT (const std::string& v)
  {
    return symbol_type (token::DOT, v);
  }

  parser::symbol_type
  parser::make_DOTDOT (const std::string& v)
  {
    return symbol_type (token::DOTDOT, v);
  }

  parser::symbol_type
  parser::make_DOTDOTDOT (const std::string& v)
  {
    return symbol_type (token::DOTDOTDOT, v);
  }

  parser::symbol_type
  parser::make_INTEGER (const std::string& v)
  {
    return symbol_type (token::INTEGER, v);
  }

  parser::symbol_type
  parser::make_DECIMAL (const std::string& v)
  {
    return symbol_type (token::DECIMAL, v);
  }

  parser::symbol_type
  parser::make_POWEROF (const std::string& v)
  {
    return symbol_type (token::POWEROF, v);
  }

  parser::symbol_type
  parser::make_HEXADECIMAL (const std::string& v)
  {
    return symbol_type (token::HEXADECIMAL, v);
  }

  parser::symbol_type
  parser::make_STRING (const std::string& v)
  {
    return symbol_type (token::STRING, v);
  }

  parser::symbol_type
  parser::make_NAME (const std::string& v)
  {
    return symbol_type (token::NAME, v);
  }



} // yy
#line 1854 "binary.tab.hh" // lalr1.cc:372




#endif // !YY_YY_BINARY_TAB_HH_INCLUDED
