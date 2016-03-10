// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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


// First part of user declarations.

#line 37 "binary.tab.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "binary.tab.hh"

// User implementation prologue.

#line 51 "binary.tab.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 11 "binary.yy" // lalr1.cc:408

  Node root;

	#define YY_DECL yy::parser::symbol_type yylex()
	YY_DECL;

#line 60 "binary.tab.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 127 "binary.tab.cc" // lalr1.cc:474

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
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
      case 75: // exp_trail
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
      case 91: // binop
      case 92: // unop
        value.move< Node > (that.value);
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
      case 27: // FORWARDSLASH
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
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
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
      case 75: // exp_trail
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
      case 91: // binop
      case 92: // unop
        value.copy< Node > (that.value);
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
      case 27: // FORWARDSLASH
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
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
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
      case 75: // exp_trail
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
      case 91: // binop
      case 92: // unop
        yylhs.value.build< Node > ();
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
      case 27: // FORWARDSLASH
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
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 118 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Start", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); root = yylhs.value.as< Node > (); }
#line 730 "binary.tab.cc" // lalr1.cc:847
    break;

  case 3:
#line 121 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 736 "binary.tab.cc" // lalr1.cc:847
    break;

  case 4:
#line 124 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", "empty"); }
#line 742 "binary.tab.cc" // lalr1.cc:847
    break;

  case 5:
#line 125 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 748 "binary.tab.cc" // lalr1.cc:847
    break;

  case 6:
#line 126 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 754 "binary.tab.cc" // lalr1.cc:847
    break;

  case 7:
#line 127 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 760 "binary.tab.cc" // lalr1.cc:847
    break;

  case 8:
#line 130 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statementchunk",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 766 "binary.tab.cc" // lalr1.cc:847
    break;

  case 9:
#line 131 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statementchunk",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("semicolon",";")); }
#line 772 "binary.tab.cc" // lalr1.cc:847
    break;

  case 10:
#line 132 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statementchunk",""); for(Node e : yystack_[1].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());  }
#line 778 "binary.tab.cc" // lalr1.cc:847
    break;

  case 11:
#line 133 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statementchunk",""); for(Node e : yystack_[2].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("semicolon",";")); }
#line 784 "binary.tab.cc" // lalr1.cc:847
    break;

  case 12:
#line 136 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 790 "binary.tab.cc" // lalr1.cc:847
    break;

  case 13:
#line 137 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("semicolon",";")); }
#line 796 "binary.tab.cc" // lalr1.cc:847
    break;

  case 14:
#line 141 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 802 "binary.tab.cc" // lalr1.cc:847
    break;

  case 15:
#line 142 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 808 "binary.tab.cc" // lalr1.cc:847
    break;

  case 16:
#line 143 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 814 "binary.tab.cc" // lalr1.cc:847
    break;

  case 17:
#line 144 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("while","while")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 820 "binary.tab.cc" // lalr1.cc:847
    break;

  case 18:
#line 145 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("repeat", "")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("until", "")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 826 "binary.tab.cc" // lalr1.cc:847
    break;

  case 19:
#line 146 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 832 "binary.tab.cc" // lalr1.cc:847
    break;

  case 20:
#line 147 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("else","else")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 838 "binary.tab.cc" // lalr1.cc:847
    break;

  case 21:
#line 148 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("else if","else if")); for (Node e : yystack_[1].value.as< Node > ().children){ yylhs.value.as< Node > ().children.push_back(e); } yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 844 "binary.tab.cc" // lalr1.cc:847
    break;

  case 22:
#line 149 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("else if","else if")); for (Node e : yystack_[3].value.as< Node > ().children){ yylhs.value.as< Node > ().children.push_back(e); } yylhs.value.as< Node > ().children.push_back(Node("else","else")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 850 "binary.tab.cc" // lalr1.cc:847
    break;

  case 23:
#line 150 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("for","for")); yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 856 "binary.tab.cc" // lalr1.cc:847
    break;

  case 24:
#line 151 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("for","for")); yylhs.value.as< Node > ().children.push_back(yystack_[9].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 862 "binary.tab.cc" // lalr1.cc:847
    break;

  case 25:
#line 152 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("for","for")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("in","in")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 868 "binary.tab.cc" // lalr1.cc:847
    break;

  case 26:
#line 153 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("function","function")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 874 "binary.tab.cc" // lalr1.cc:847
    break;

  case 27:
#line 154 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("local","local")); yylhs.value.as< Node > ().children.push_back(Node("function","function")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 880 "binary.tab.cc" // lalr1.cc:847
    break;

  case 28:
#line 155 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("local","local")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 886 "binary.tab.cc" // lalr1.cc:847
    break;

  case 29:
#line 156 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement",""); yylhs.value.as< Node > ().children.push_back(Node("local","local")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 892 "binary.tab.cc" // lalr1.cc:847
    break;

  case 30:
#line 159 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("else if","else if"); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 898 "binary.tab.cc" // lalr1.cc:847
    break;

  case 31:
#line 160 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[4].value.as< Node > ();  yylhs.value.as< Node > ().children.push_back(Node("else if","else if")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 904 "binary.tab.cc" // lalr1.cc:847
    break;

  case 32:
#line 163 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Last statement",""); yylhs.value.as< Node > ().children.push_back(Node("return","return")); }
#line 910 "binary.tab.cc" // lalr1.cc:847
    break;

  case 33:
#line 164 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Last statement",""); yylhs.value.as< Node > ().children.push_back(Node("return","return")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 916 "binary.tab.cc" // lalr1.cc:847
    break;

  case 34:
#line 165 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Last statement",""); yylhs.value.as< Node > ().children.push_back(Node("break","break")); }
#line 922 "binary.tab.cc" // lalr1.cc:847
    break;

  case 35:
#line 167 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 928 "binary.tab.cc" // lalr1.cc:847
    break;

  case 36:
#line 168 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("colon",":")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 934 "binary.tab.cc" // lalr1.cc:847
    break;

  case 37:
#line 169 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} 	}
#line 940 "binary.tab.cc" // lalr1.cc:847
    break;

  case 38:
#line 170 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); for(Node e : yystack_[2].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(Node("colon",":")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 946 "binary.tab.cc" // lalr1.cc:847
    break;

  case 39:
#line 173 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("dot","."); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 952 "binary.tab.cc" // lalr1.cc:847
    break;

  case 40:
#line 174 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("dot",".")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 958 "binary.tab.cc" // lalr1.cc:847
    break;

  case 41:
#line 177 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("varlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 964 "binary.tab.cc" // lalr1.cc:847
    break;

  case 42:
#line 178 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("varlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} }
#line 970 "binary.tab.cc" // lalr1.cc:847
    break;

  case 43:
#line 181 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("comma",","); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 976 "binary.tab.cc" // lalr1.cc:847
    break;

  case 44:
#line 182 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 982 "binary.tab.cc" // lalr1.cc:847
    break;

  case 45:
#line 185 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("var",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 988 "binary.tab.cc" // lalr1.cc:847
    break;

  case 46:
#line 186 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("var",""); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("leftbracket","[")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightbracket","]")); }
#line 994 "binary.tab.cc" // lalr1.cc:847
    break;

  case 47:
#line 187 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("var",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("dot","."));}
#line 1000 "binary.tab.cc" // lalr1.cc:847
    break;

  case 48:
#line 190 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("namelist", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1006 "binary.tab.cc" // lalr1.cc:847
    break;

  case 49:
#line 191 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("namelist", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} }
#line 1012 "binary.tab.cc" // lalr1.cc:847
    break;

  case 50:
#line 194 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("namelist_layer",""); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1018 "binary.tab.cc" // lalr1.cc:847
    break;

  case 51:
#line 195 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1024 "binary.tab.cc" // lalr1.cc:847
    break;

  case 52:
#line 198 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("explist", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1030 "binary.tab.cc" // lalr1.cc:847
    break;

  case 53:
#line 199 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("explist", ""); for(Node e: yystack_[1].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1036 "binary.tab.cc" // lalr1.cc:847
    break;

  case 54:
#line 202 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("explist_layer",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); }
#line 1042 "binary.tab.cc" // lalr1.cc:847
    break;

  case 55:
#line 203 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); }
#line 1048 "binary.tab.cc" // lalr1.cc:847
    break;

  case 56:
#line 207 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("exp",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1054 "binary.tab.cc" // lalr1.cc:847
    break;

  case 57:
#line 208 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("exp",""); for(Node e : yystack_[2].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1060 "binary.tab.cc" // lalr1.cc:847
    break;

  case 58:
#line 209 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("exp",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1066 "binary.tab.cc" // lalr1.cc:847
    break;

  case 59:
#line 212 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1072 "binary.tab.cc" // lalr1.cc:847
    break;

  case 60:
#line 215 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("nil",yystack_[0].value.as< std::string > ());}
#line 1078 "binary.tab.cc" // lalr1.cc:847
    break;

  case 61:
#line 216 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("false",yystack_[0].value.as< std::string > ());}
#line 1084 "binary.tab.cc" // lalr1.cc:847
    break;

  case 62:
#line 217 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("true",yystack_[0].value.as< std::string > ());}
#line 1090 "binary.tab.cc" // lalr1.cc:847
    break;

  case 63:
#line 218 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1096 "binary.tab.cc" // lalr1.cc:847
    break;

  case 64:
#line 219 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1102 "binary.tab.cc" // lalr1.cc:847
    break;

  case 65:
#line 220 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("dotdotdot",yystack_[0].value.as< std::string > ());}
#line 1108 "binary.tab.cc" // lalr1.cc:847
    break;

  case 66:
#line 221 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1114 "binary.tab.cc" // lalr1.cc:847
    break;

  case 67:
#line 222 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1120 "binary.tab.cc" // lalr1.cc:847
    break;

  case 68:
#line 223 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1126 "binary.tab.cc" // lalr1.cc:847
    break;

  case 69:
#line 226 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("integer", yystack_[0].value.as< std::string > ()); }
#line 1132 "binary.tab.cc" // lalr1.cc:847
    break;

  case 70:
#line 227 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("decimal", yystack_[0].value.as< std::string > ());}
#line 1138 "binary.tab.cc" // lalr1.cc:847
    break;

  case 71:
#line 228 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("powerof", yystack_[0].value.as< std::string > ());}
#line 1144 "binary.tab.cc" // lalr1.cc:847
    break;

  case 72:
#line 229 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("hexadecimal", yystack_[0].value.as< std::string > ());}
#line 1150 "binary.tab.cc" // lalr1.cc:847
    break;

  case 73:
#line 232 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Identifier", yystack_[0].value.as< std::string > ()); }
#line 1156 "binary.tab.cc" // lalr1.cc:847
    break;

  case 74:
#line 235 "binary.yy" // lalr1.cc:847
    { std::string temp; for(int i=1;i<yystack_[0].value.as< std::string > ().length()-1;i++){temp = temp + yystack_[0].value.as< std::string > ()[i];}  yylhs.value.as< Node > () = Node("String",temp);}
#line 1162 "binary.tab.cc" // lalr1.cc:847
    break;

  case 75:
#line 238 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("prefixexp",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1168 "binary.tab.cc" // lalr1.cc:847
    break;

  case 76:
#line 239 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("prefixexp",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1174 "binary.tab.cc" // lalr1.cc:847
    break;

  case 77:
#line 240 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("prefixexp",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(Node(yystack_[1].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); }
#line 1180 "binary.tab.cc" // lalr1.cc:847
    break;

  case 78:
#line 243 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("functioncall",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1186 "binary.tab.cc" // lalr1.cc:847
    break;

  case 79:
#line 244 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("functioncall",""); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("colon",":")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1192 "binary.tab.cc" // lalr1.cc:847
    break;

  case 80:
#line 247 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); }
#line 1198 "binary.tab.cc" // lalr1.cc:847
    break;

  case 81:
#line 248 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")"));}
#line 1204 "binary.tab.cc" // lalr1.cc:847
    break;

  case 82:
#line 249 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1210 "binary.tab.cc" // lalr1.cc:847
    break;

  case 83:
#line 250 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1216 "binary.tab.cc" // lalr1.cc:847
    break;

  case 84:
#line 253 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("function","function"); yylhs.value.as< Node > ().children.push_back(Node("function","function")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1222 "binary.tab.cc" // lalr1.cc:847
    break;

  case 85:
#line 256 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 1228 "binary.tab.cc" // lalr1.cc:847
    break;

  case 86:
#line 257 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 1234 "binary.tab.cc" // lalr1.cc:847
    break;

  case 87:
#line 260 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1240 "binary.tab.cc" // lalr1.cc:847
    break;

  case 88:
#line 261 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(Node("dotdotdot","...")); }
#line 1246 "binary.tab.cc" // lalr1.cc:847
    break;

  case 89:
#line 262 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(Node("dotdotdot","..."));}
#line 1252 "binary.tab.cc" // lalr1.cc:847
    break;

  case 90:
#line 265 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("tableconstructor",""); yylhs.value.as< Node > ().children.push_back(Node("leftbraces","[")); yylhs.value.as< Node > ().children.push_back(Node("rightbraces","]")); }
#line 1258 "binary.tab.cc" // lalr1.cc:847
    break;

  case 91:
#line 266 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("tableconstructor",""); yylhs.value.as< Node > ().children.push_back(Node("leftbraces","[")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightbraces","]"));}
#line 1264 "binary.tab.cc" // lalr1.cc:847
    break;

  case 92:
#line 269 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1270 "binary.tab.cc" // lalr1.cc:847
    break;

  case 93:
#line 270 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);}}
#line 1276 "binary.tab.cc" // lalr1.cc:847
    break;

  case 94:
#line 271 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1282 "binary.tab.cc" // lalr1.cc:847
    break;

  case 95:
#line 272 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); for(Node e : yystack_[1].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1288 "binary.tab.cc" // lalr1.cc:847
    break;

  case 96:
#line 275 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist_layer",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1294 "binary.tab.cc" // lalr1.cc:847
    break;

  case 97:
#line 276 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1300 "binary.tab.cc" // lalr1.cc:847
    break;

  case 98:
#line 279 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("field",""); yylhs.value.as< Node > ().children.push_back(Node("leftbracket","[")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightbracket","]")); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1306 "binary.tab.cc" // lalr1.cc:847
    break;

  case 99:
#line 280 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("field",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1312 "binary.tab.cc" // lalr1.cc:847
    break;

  case 100:
#line 281 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("field",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1318 "binary.tab.cc" // lalr1.cc:847
    break;

  case 101:
#line 284 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Fieldsep", yystack_[0].value.as< std::string > ());}
#line 1324 "binary.tab.cc" // lalr1.cc:847
    break;

  case 102:
#line 285 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Fieldsep", yystack_[0].value.as< std::string > ());}
#line 1330 "binary.tab.cc" // lalr1.cc:847
    break;

  case 103:
#line 288 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1336 "binary.tab.cc" // lalr1.cc:847
    break;

  case 104:
#line 289 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1342 "binary.tab.cc" // lalr1.cc:847
    break;

  case 105:
#line 290 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1348 "binary.tab.cc" // lalr1.cc:847
    break;

  case 106:
#line 291 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1354 "binary.tab.cc" // lalr1.cc:847
    break;

  case 107:
#line 292 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1360 "binary.tab.cc" // lalr1.cc:847
    break;

  case 108:
#line 293 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1366 "binary.tab.cc" // lalr1.cc:847
    break;

  case 109:
#line 294 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1372 "binary.tab.cc" // lalr1.cc:847
    break;

  case 110:
#line 295 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1378 "binary.tab.cc" // lalr1.cc:847
    break;

  case 111:
#line 296 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1384 "binary.tab.cc" // lalr1.cc:847
    break;

  case 112:
#line 297 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1390 "binary.tab.cc" // lalr1.cc:847
    break;

  case 113:
#line 298 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1396 "binary.tab.cc" // lalr1.cc:847
    break;

  case 114:
#line 299 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1402 "binary.tab.cc" // lalr1.cc:847
    break;

  case 115:
#line 300 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1408 "binary.tab.cc" // lalr1.cc:847
    break;

  case 116:
#line 301 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1414 "binary.tab.cc" // lalr1.cc:847
    break;

  case 117:
#line 302 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("binop", yystack_[0].value.as< std::string > ());}
#line 1420 "binary.tab.cc" // lalr1.cc:847
    break;

  case 118:
#line 305 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ());}
#line 1426 "binary.tab.cc" // lalr1.cc:847
    break;

  case 119:
#line 306 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ());}
#line 1432 "binary.tab.cc" // lalr1.cc:847
    break;

  case 120:
#line 307 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("unop", yystack_[0].value.as< std::string > ());}
#line 1438 "binary.tab.cc" // lalr1.cc:847
    break;


#line 1442 "binary.tab.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -127;

  const signed char parser::yytable_ninf_ = -77;

  const short int
  parser::yypact_[] =
  {
     221,  -127,   221,   -36,   -36,   323,    -5,   221,   323,   323,
     323,  -127,    29,  -127,  -127,   221,  -127,    -3,     4,    15,
     -16,  -127,    17,    25,    50,    71,   -14,    47,   -23,  -127,
      47,  -127,  -127,  -127,  -127,  -127,   240,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,   411,  -127,  -127,  -127,    17,  -127,
    -127,  -127,   323,   -36,    53,    41,    69,  -127,   323,   438,
     472,   499,  -127,  -127,    48,  -127,  -127,   323,   -28,    52,
     258,   323,   -36,   -36,  -127,  -127,  -127,  -127,   323,   323,
     -36,    54,   -11,  -127,   -36,   -36,    16,  -127,  -127,   323,
     722,    56,    58,    33,  -127,  -127,   221,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
     331,   722,    47,   323,   323,   526,  -127,   221,  -127,  -127,
    -127,     3,   -28,  -127,    55,   553,    -1,  -127,    96,   580,
    -127,   -36,   221,  -127,    59,    65,  -127,  -127,   -36,   -36,
     607,   323,  -127,  -127,  -127,    33,   305,    68,  -127,  -127,
    -127,  -127,   722,  -127,    98,     8,  -127,  -127,  -127,   221,
     323,  -127,   103,    70,   221,  -127,  -127,    83,   722,   305,
    -127,   221,   323,  -127,    74,  -127,   113,   384,  -127,  -127,
     116,   323,  -127,   117,   634,   221,   323,  -127,  -127,   221,
     323,  -127,   722,  -127,   221,   119,   661,   121,   695,  -127,
    -127,   221,  -127,   221,  -127,   122,  -127
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,    34,     4,     0,     0,     0,     0,     4,    32,     0,
       0,    73,     0,     2,     3,     5,     7,     8,    12,     0,
      75,    45,     0,    15,     0,     0,    48,     0,    35,    61,
       0,    60,   119,    62,   118,   120,     0,    65,    69,    70,
      71,    72,    74,    75,     0,    56,    63,    64,    67,    76,
      66,    68,     0,     0,    28,    48,     0,    33,     0,    52,
       0,     0,     1,     6,    10,     9,    13,     0,     0,    42,
       0,     0,     0,     0,    83,    78,    82,    16,     0,     0,
       0,    49,     0,    26,     0,     0,    37,    84,    90,     0,
     100,    45,     0,    92,   116,   117,     4,   103,   104,   105,
     106,   108,   107,   114,   115,   111,   113,   110,   112,   109,
       0,    58,     0,     0,     0,    53,    54,     4,    77,    11,
      14,    75,     0,    80,     0,     0,     0,    47,     0,     0,
      50,     0,     4,    89,    87,     0,    36,    39,     0,     0,
       0,     0,    91,   102,   101,    93,    94,     0,    57,    59,
      27,    29,    18,    55,     0,    75,    81,    46,    79,     4,
       0,    51,     0,     0,     4,    38,    40,     0,    99,    95,
      96,     4,     0,    19,     0,    17,     0,     0,    85,    88,
       0,     0,    97,     0,     0,     4,     0,    21,    25,     4,
       0,    86,    98,    20,     4,     0,     0,     0,     0,    30,
      22,     4,    23,     4,    31,     0,    24
  };

  const signed char
  parser::yypgoto_[] =
  {
    -127,  -127,    49,  -127,  -127,   120,   123,  -127,  -127,  -127,
    -127,  -127,  -127,     0,     6,  -127,   -53,  -127,    37,  -127,
      21,  -127,    30,   -17,     1,    11,    10,  -127,   -26,  -127,
     -13,  -127,  -127,  -126,    -8,  -127,  -127
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,   174,    18,    27,
      86,    19,    69,    43,    25,    81,    57,    58,    59,   148,
      45,    46,    21,    47,    48,    49,    75,    50,    83,   135,
      51,    92,   145,    93,   146,   110,    52
  };

  const short int
  parser::yytable_[] =
  {
      20,    22,    20,    22,    87,    74,    53,    20,    22,    76,
      10,    23,    54,    23,   120,    20,    22,   124,    23,    11,
     170,   -41,    84,    79,    85,   128,    23,    11,   132,    62,
      68,    74,    80,    26,    28,    76,    55,    70,   133,    36,
     -43,    65,    44,   182,    11,   -44,    60,    61,    66,   -43,
      11,    24,    67,    42,   -44,    70,    56,    36,    77,    71,
     151,   138,    72,   139,    73,   -76,    91,   -76,   121,    22,
     -76,    42,   -76,    90,   171,   172,   173,   143,   144,   -76,
     185,   186,   187,   112,    78,    82,   150,    80,   134,   111,
     113,   114,   119,   141,   156,   115,    20,    22,   122,   142,
     131,   159,   126,   127,   164,   163,   175,    23,   125,    74,
     130,   178,    55,    76,   136,   137,   129,    20,    22,   179,
     181,   188,   155,    22,   191,   193,   140,   200,    23,   202,
     206,   149,    20,    22,     0,    63,   158,   169,    64,     0,
       0,     0,     0,    23,     0,   147,     0,     0,     0,     0,
       0,   152,     0,     0,     0,     0,     0,     0,     0,    20,
      22,   161,     0,     0,    20,    22,   154,     0,   165,   166,
      23,    20,    22,     0,     0,    23,    91,     0,   168,     0,
       0,   162,    23,    90,     0,    20,    22,     0,     0,    20,
      22,     0,     0,     0,    20,    22,    23,   177,     0,    91,
      23,    20,    22,    20,    22,    23,    90,     0,   176,   184,
       0,     0,    23,   180,    23,     0,     0,     0,   192,     0,
     183,     0,     0,   196,     0,     1,     2,   198,     0,     0,
       0,     3,     4,     5,   195,     6,     0,     0,   197,     7,
       8,     0,     0,   199,     9,     0,     0,     0,     0,    29,
     204,    30,   205,     0,     0,    31,    32,     0,     0,    10,
       0,    33,     0,     0,     0,    34,     0,    29,     0,    30,
      35,     0,     0,    31,    32,     0,    11,     0,    10,    33,
      36,    88,    89,    34,     0,     0,     0,     0,    35,    37,
      38,    39,    40,    41,    42,    11,    10,   123,    36,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    39,
      40,    41,    42,    11,    29,     0,    30,     0,     0,     0,
      31,    32,     0,     0,     0,     0,    33,     0,     0,     0,
      34,     0,    29,     0,    30,    35,     0,     0,    31,    32,
      29,     0,    30,    10,    33,    36,    31,    89,    34,     0,
       0,     0,    33,    35,    37,    38,    39,    40,    41,    42,
      11,    10,     0,    36,     0,     0,     0,     0,     0,    10,
       0,    36,    37,    38,    39,    40,    41,    42,    11,     0,
      37,    38,    39,    40,    41,    42,    11,    94,     0,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,    94,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,     0,     0,     0,    95,     0,
     190,    96,   109,     0,     0,    97,    98,    99,   100,   101,
     102,    94,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,   109,
       0,     0,    97,    98,    99,   100,   101,   102,     0,   103,
     104,   105,   106,   107,   108,    94,     0,   117,     0,     0,
       0,     0,     0,     0,   116,     0,   109,     0,     0,    95,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,    94,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
     109,     0,     0,    97,    98,    99,   100,   101,   102,    94,
     103,   104,   105,   106,   107,   108,     0,     0,   118,     0,
       0,     0,     0,    95,     0,     0,     0,   109,     0,     0,
      97,    98,    99,   100,   101,   102,    94,   103,   104,   105,
     106,   107,   108,     0,     0,     0,     0,     0,     0,     0,
      95,     0,   153,     0,   109,     0,     0,    97,    98,    99,
     100,   101,   102,    94,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   157,    95,     0,     0,
       0,   109,     0,     0,    97,    98,    99,   100,   101,   102,
      94,   103,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,    95,     0,   160,     0,   109,     0,
       0,    97,    98,    99,   100,   101,   102,    94,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
     167,    95,     0,     0,   194,   109,     0,     0,    97,    98,
      99,   100,   101,   102,    94,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,   201,   109,     0,     0,    97,    98,    99,   100,   101,
     102,     0,   103,   104,   105,   106,   107,   108,    94,     0,
     203,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,    95,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,    94,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,   109,     0,     0,    97,    98,    99,   100,
     101,   102,     0,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,    30,    22,    11,     7,     7,    22,
      38,     0,     6,     2,    67,    15,    15,    70,     7,    55,
     146,    37,    45,    37,    47,    78,    15,    55,    39,     0,
      46,    48,    46,     3,     4,    48,     6,    38,    49,    40,
      37,    44,     5,   169,    55,    37,     9,    10,    44,    46,
      55,     2,    37,    54,    46,    38,     7,    40,     8,    42,
     113,    45,    45,    47,    47,    40,    36,    42,    68,    68,
      45,    54,    47,    36,     6,     7,     8,    44,    45,    54,
       6,     7,     8,    53,    13,    38,   112,    46,    82,    52,
      37,    22,    44,    37,    39,    58,    96,    96,    46,    41,
      46,     5,    72,    73,    39,    46,     8,    96,    71,   126,
      80,     8,    82,   126,    84,    85,    79,   117,   117,    49,
      37,     8,   122,   122,     8,     8,    89,     8,   117,     8,
       8,   110,   132,   132,    -1,    15,   126,   145,    15,    -1,
      -1,    -1,    -1,   132,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     159,   131,    -1,    -1,   164,   164,   117,    -1,   138,   139,
     159,   171,   171,    -1,    -1,   164,   146,    -1,   141,    -1,
      -1,   132,   171,   146,    -1,   185,   185,    -1,    -1,   189,
     189,    -1,    -1,    -1,   194,   194,   185,   160,    -1,   169,
     189,   201,   201,   203,   203,   194,   169,    -1,   159,   172,
      -1,    -1,   201,   164,   203,    -1,    -1,    -1,   181,    -1,
     171,    -1,    -1,   186,    -1,     4,     5,   190,    -1,    -1,
      -1,    10,    11,    12,   185,    14,    -1,    -1,   189,    18,
      19,    -1,    -1,   194,    23,    -1,    -1,    -1,    -1,     9,
     201,    11,   203,    -1,    -1,    15,    16,    -1,    -1,    38,
      -1,    21,    -1,    -1,    -1,    25,    -1,     9,    -1,    11,
      30,    -1,    -1,    15,    16,    -1,    55,    -1,    38,    21,
      40,    41,    42,    25,    -1,    -1,    -1,    -1,    30,    49,
      50,    51,    52,    53,    54,    55,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      25,    -1,     9,    -1,    11,    30,    -1,    -1,    15,    16,
       9,    -1,    11,    38,    21,    40,    15,    42,    25,    -1,
      -1,    -1,    21,    30,    49,    50,    51,    52,    53,    54,
      55,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    49,    50,    51,    52,    53,    54,    55,    -1,
      49,    50,    51,    52,    53,    54,    55,     3,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    29,     3,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      46,    20,    48,    -1,    -1,    24,    25,    26,    27,    28,
      29,     3,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    48,
      -1,    -1,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,     3,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,     3,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      48,    -1,    -1,    24,    25,    26,    27,    28,    29,     3,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    48,    -1,    -1,
      24,    25,    26,    27,    28,    29,     3,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    46,    -1,    48,    -1,    -1,    24,    25,    26,
      27,    28,    29,     3,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    17,    -1,    -1,
      -1,    48,    -1,    -1,    24,    25,    26,    27,    28,    29,
       3,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    46,    -1,    48,    -1,
      -1,    24,    25,    26,    27,    28,    29,     3,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    17,    -1,    -1,    20,    48,    -1,    -1,    24,    25,
      26,    27,    28,    29,     3,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    48,    -1,    -1,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,     3,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,     3,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    48,    -1,    -1,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     5,    10,    11,    12,    14,    18,    19,    23,
      38,    55,    57,    58,    59,    60,    61,    62,    64,    67,
      69,    78,    80,    81,    58,    70,    78,    65,    78,     9,
      11,    15,    16,    21,    25,    30,    40,    49,    50,    51,
      52,    53,    54,    69,    74,    76,    77,    79,    80,    81,
      83,    86,    92,    11,    70,    78,    58,    72,    73,    74,
      74,    74,     0,    61,    62,    44,    44,    37,    46,    68,
      38,    42,    45,    47,    79,    82,    86,     8,    13,    37,
      46,    71,    38,    84,    45,    47,    66,    84,    41,    42,
      74,    78,    87,    89,     3,    17,    20,    24,    25,    26,
      27,    28,    29,    31,    32,    33,    34,    35,    36,    48,
      91,    74,    78,    37,    22,    74,    46,     5,    39,    44,
      72,    69,    46,    39,    72,    74,    78,    78,    72,    74,
      78,    46,    39,    49,    70,    85,    78,    78,    45,    47,
      74,    37,    41,    44,    45,    88,    90,    58,    75,    76,
      84,    72,    74,    46,    58,    69,    39,    43,    82,     5,
      46,    78,    58,    46,    39,    78,    78,    43,    74,    90,
      89,     6,     7,     8,    63,     8,    58,    74,     8,    49,
      58,    37,    89,    58,    74,     6,     7,     8,     8,     5,
      46,     8,    74,     8,    20,    58,    74,    58,    74,    58,
       8,    20,     8,     5,    58,    58,     8
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    56,    57,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    78,    79,    80,    80,    80,    81,    81,
      82,    82,    82,    82,    83,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    87,    87,    88,    88,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     0,     1,     2,     1,     1,     2,
       2,     3,     1,     2,     3,     1,     3,     5,     4,     5,
       7,     6,     8,     9,    11,     7,     3,     4,     2,     4,
       4,     5,     1,     2,     1,     1,     3,     2,     4,     2,
       3,     1,     2,     2,     3,     1,     4,     3,     1,     2,
       2,     3,     1,     2,     2,     3,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     4,
       2,     3,     1,     1,     2,     4,     5,     1,     3,     1,
       2,     3,     1,     2,     2,     3,     2,     3,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "AND", "BREAK", "DO", "ELSE",
  "ELSEIF", "end", "FALSE", "FOR", "FUNCTION", "IF", "IN", "LOCAL", "NIL",
  "NOT", "OR", "REPEAT", "RETURN", "THEN", "TRUE", "UNTIL", "WHILE",
  "PLUS", "MINUS", "MULTIPLY", "FORWARDSLASH", "PERCENT", "CARET",
  "HASHTAG", "EQUALTO", "TILDEEQUAL", "LESSOREQUAL", "GREATEROREQUAL",
  "LESSTHAN", "GREATERTHAN", "EQUAL", "LEFTPARENTHESES",
  "RIGHTPARENTHESES", "LEFTBRACES", "RIGHTBRACES", "LEFTBRACKET",
  "RIGHTBRACKET", "SEMICOLON", "COLON", "COMMA", "DOT", "DOTDOT",
  "DOTDOTDOT", "INTEGER", "DECIMAL", "POWEROF", "HEXADECIMAL", "STRING",
  "NAME", "$accept", "S", "block", "chunk", "chunk_layer",
  "laststat_layer", "stat", "elseif_layer", "laststat", "funcname",
  "funcname_layer", "varlist", "varlist_layer", "var", "namelist",
  "namelist_layer", "explist", "explist_layer", "exp", "exp_trail",
  "exp_layer", "Number", "Name", "String", "prefixexp", "functioncall",
  "args", "function", "funcbody", "parlist", "tableconstructor",
  "fieldlist", "fieldlist_layer", "field", "fieldsep", "binop", "unop", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   118,   118,   121,   124,   125,   126,   127,   130,   131,
     132,   133,   136,   137,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     159,   160,   163,   164,   165,   167,   168,   169,   170,   173,
     174,   177,   178,   181,   182,   185,   186,   187,   190,   191,
     194,   195,   198,   199,   202,   203,   207,   208,   209,   212,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   226,
     227,   228,   229,   232,   235,   238,   239,   240,   243,   244,
     247,   248,   249,   250,   253,   256,   257,   260,   261,   262,
     265,   266,   269,   270,   271,   272,   275,   276,   279,   280,
     281,   284,   285,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   305,   306,
     307
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1982 "binary.tab.cc" // lalr1.cc:1155
