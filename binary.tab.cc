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
      case 76: // exp_layer
      case 77: // Number
      case 78: // prefixexp
      case 79: // functioncall
      case 80: // args
      case 81: // function
      case 82: // funcbody
      case 83: // parlist
      case 84: // tableconstructor
      case 85: // fieldlist
      case 86: // fieldlist_layer
      case 87: // field
      case 88: // fieldsep
      case 89: // binop
      case 90: // unop
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
      case 54: // String
      case 55: // Name
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
      case 76: // exp_layer
      case 77: // Number
      case 78: // prefixexp
      case 79: // functioncall
      case 80: // args
      case 81: // function
      case 82: // funcbody
      case 83: // parlist
      case 84: // tableconstructor
      case 85: // fieldlist
      case 86: // fieldlist_layer
      case 87: // field
      case 88: // fieldsep
      case 89: // binop
      case 90: // unop
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
      case 54: // String
      case 55: // Name
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
      case 76: // exp_layer
      case 77: // Number
      case 78: // prefixexp
      case 79: // functioncall
      case 80: // args
      case 81: // function
      case 82: // funcbody
      case 83: // parlist
      case 84: // tableconstructor
      case 85: // fieldlist
      case 86: // fieldlist_layer
      case 87: // field
      case 88: // fieldsep
      case 89: // binop
      case 90: // unop
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
      case 54: // String
      case 55: // Name
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
#line 115 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Start", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); root = yylhs.value.as< Node > (); }
#line 721 "binary.tab.cc" // lalr1.cc:847
    break;

  case 3:
#line 118 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 727 "binary.tab.cc" // lalr1.cc:847
    break;

  case 4:
#line 121 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", "empty"); }
#line 733 "binary.tab.cc" // lalr1.cc:847
    break;

  case 5:
#line 122 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 739 "binary.tab.cc" // lalr1.cc:847
    break;

  case 6:
#line 123 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 745 "binary.tab.cc" // lalr1.cc:847
    break;

  case 7:
#line 124 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 751 "binary.tab.cc" // lalr1.cc:847
    break;

  case 8:
#line 127 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 757 "binary.tab.cc" // lalr1.cc:847
    break;

  case 9:
#line 128 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 763 "binary.tab.cc" // lalr1.cc:847
    break;

  case 10:
#line 129 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 769 "binary.tab.cc" // lalr1.cc:847
    break;

  case 11:
#line 130 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 775 "binary.tab.cc" // lalr1.cc:847
    break;

  case 12:
#line 133 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Last statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 781 "binary.tab.cc" // lalr1.cc:847
    break;

  case 13:
#line 134 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Last statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 787 "binary.tab.cc" // lalr1.cc:847
    break;

  case 14:
#line 138 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Operator", "equals:"); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 793 "binary.tab.cc" // lalr1.cc:847
    break;

  case 15:
#line 139 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Functioncall",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 799 "binary.tab.cc" // lalr1.cc:847
    break;

  case 16:
#line 140 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();}
#line 805 "binary.tab.cc" // lalr1.cc:847
    break;

  case 17:
#line 141 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("While", ""); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("Do","")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 811 "binary.tab.cc" // lalr1.cc:847
    break;

  case 18:
#line 142 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Repeat", yystack_[0].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); }
#line 817 "binary.tab.cc" // lalr1.cc:847
    break;

  case 19:
#line 143 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Condition", ""); yylhs.value.as< Node > ().children.push_back(Node("If", yystack_[3].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("Then", yystack_[1].value.as< Node > ()););  }
#line 823 "binary.tab.cc" // lalr1.cc:847
    break;

  case 20:
#line 144 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Condition", ""); yylhs.value.as< Node > ().children.push_back(Node("If", yystack_[5].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("Then", yystack_[3].value.as< Node > ());); yylhs.value.as< Node > ().children.push_back(Node("Else", yystack_[1].value.as< Node > ())); }
#line 829 "binary.tab.cc" // lalr1.cc:847
    break;

  case 21:
#line 145 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Condition", ""); yylhs.value.as< Node > ().children.push_back(Node("If", yystack_[4].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("Then", yystack_[2].value.as< Node > ());); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); }
#line 835 "binary.tab.cc" // lalr1.cc:847
    break;

  case 22:
#line 146 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Condition", ""); yylhs.value.as< Node > ().children.push_back(Node("If", yystack_[6].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("Then", yystack_[4].value.as< Node > ());); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("Else", yystack_[1].value.as< Node > ()));}
#line 841 "binary.tab.cc" // lalr1.cc:847
    break;

  case 23:
#line 147 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("For", ""); Node equal("Equal", ); equal.children.push_back(yystack_[7].value.as< std::string > ()); equal.children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(equal); yylhs.value.as< Node > ().children.push_back(Node("Exp", yystack_[3].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("Do", yystack_[1].value.as< Node > ())); }
#line 847 "binary.tab.cc" // lalr1.cc:847
    break;

  case 24:
#line 148 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("For", ""); Node equal("Equal", ); equal.children.push_back(yystack_[9].value.as< std::string > ()); equal.children.push_back(yystack_[7].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(equal); yylhs.value.as< Node > ().children.push_back(Node("Exp", yystack_[5].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("Exp", yystack_[3].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("Do", yystack_[1].value.as< Node > ()));}
#line 853 "binary.tab.cc" // lalr1.cc:847
    break;

  case 25:
#line 149 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("For", ""); Node in("In", ""); in.children.push_back(yystack_[5].value.as< Node > ()); in.children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(in); yylhs.value.as< Node > ().children.push_back(Node("Do", yystack_[1].value.as< Node > ()));}
#line 859 "binary.tab.cc" // lalr1.cc:847
    break;

  case 26:
#line 150 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Function", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 865 "binary.tab.cc" // lalr1.cc:847
    break;

  case 27:
#line 151 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Local Function", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< std::string > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 871 "binary.tab.cc" // lalr1.cc:847
    break;

  case 28:
#line 152 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 877 "binary.tab.cc" // lalr1.cc:847
    break;

  case 29:
#line 153 "binary.yy" // lalr1.cc:847
    {}
#line 883 "binary.tab.cc" // lalr1.cc:847
    break;

  case 30:
#line 156 "binary.yy" // lalr1.cc:847
    {}
#line 889 "binary.tab.cc" // lalr1.cc:847
    break;

  case 31:
#line 157 "binary.yy" // lalr1.cc:847
    {}
#line 895 "binary.tab.cc" // lalr1.cc:847
    break;

  case 32:
#line 160 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement","return");}
#line 901 "binary.tab.cc" // lalr1.cc:847
    break;

  case 33:
#line 161 "binary.yy" // lalr1.cc:847
    {}
#line 907 "binary.tab.cc" // lalr1.cc:847
    break;

  case 34:
#line 162 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Statement","break");}
#line 913 "binary.tab.cc" // lalr1.cc:847
    break;

  case 35:
#line 164 "binary.yy" // lalr1.cc:847
    {}
#line 919 "binary.tab.cc" // lalr1.cc:847
    break;

  case 36:
#line 165 "binary.yy" // lalr1.cc:847
    {}
#line 925 "binary.tab.cc" // lalr1.cc:847
    break;

  case 37:
#line 166 "binary.yy" // lalr1.cc:847
    {}
#line 931 "binary.tab.cc" // lalr1.cc:847
    break;

  case 38:
#line 167 "binary.yy" // lalr1.cc:847
    {}
#line 937 "binary.tab.cc" // lalr1.cc:847
    break;

  case 39:
#line 170 "binary.yy" // lalr1.cc:847
    {}
#line 943 "binary.tab.cc" // lalr1.cc:847
    break;

  case 40:
#line 171 "binary.yy" // lalr1.cc:847
    {}
#line 949 "binary.tab.cc" // lalr1.cc:847
    break;

  case 41:
#line 174 "binary.yy" // lalr1.cc:847
    {yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 955 "binary.tab.cc" // lalr1.cc:847
    break;

  case 42:
#line 175 "binary.yy" // lalr1.cc:847
    {}
#line 961 "binary.tab.cc" // lalr1.cc:847
    break;

  case 43:
#line 178 "binary.yy" // lalr1.cc:847
    {}
#line 967 "binary.tab.cc" // lalr1.cc:847
    break;

  case 44:
#line 179 "binary.yy" // lalr1.cc:847
    {}
#line 973 "binary.tab.cc" // lalr1.cc:847
    break;

  case 45:
#line 182 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Identifier",yystack_[0].value.as< std::string > ()); }
#line 979 "binary.tab.cc" // lalr1.cc:847
    break;

  case 46:
#line 183 "binary.yy" // lalr1.cc:847
    {}
#line 985 "binary.tab.cc" // lalr1.cc:847
    break;

  case 47:
#line 184 "binary.yy" // lalr1.cc:847
    {}
#line 991 "binary.tab.cc" // lalr1.cc:847
    break;

  case 48:
#line 187 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Namelist", yystack_[0].value.as< std::string > ()); }
#line 997 "binary.tab.cc" // lalr1.cc:847
    break;

  case 49:
#line 188 "binary.yy" // lalr1.cc:847
    {}
#line 1003 "binary.tab.cc" // lalr1.cc:847
    break;

  case 50:
#line 191 "binary.yy" // lalr1.cc:847
    {}
#line 1009 "binary.tab.cc" // lalr1.cc:847
    break;

  case 51:
#line 192 "binary.yy" // lalr1.cc:847
    {}
#line 1015 "binary.tab.cc" // lalr1.cc:847
    break;

  case 52:
#line 195 "binary.yy" // lalr1.cc:847
    {}
#line 1021 "binary.tab.cc" // lalr1.cc:847
    break;

  case 53:
#line 196 "binary.yy" // lalr1.cc:847
    {}
#line 1027 "binary.tab.cc" // lalr1.cc:847
    break;

  case 54:
#line 199 "binary.yy" // lalr1.cc:847
    {}
#line 1033 "binary.tab.cc" // lalr1.cc:847
    break;

  case 55:
#line 200 "binary.yy" // lalr1.cc:847
    {}
#line 1039 "binary.tab.cc" // lalr1.cc:847
    break;

  case 56:
#line 204 "binary.yy" // lalr1.cc:847
    {}
#line 1045 "binary.tab.cc" // lalr1.cc:847
    break;

  case 57:
#line 205 "binary.yy" // lalr1.cc:847
    {}
#line 1051 "binary.tab.cc" // lalr1.cc:847
    break;

  case 58:
#line 206 "binary.yy" // lalr1.cc:847
    {}
#line 1057 "binary.tab.cc" // lalr1.cc:847
    break;

  case 61:
#line 212 "binary.yy" // lalr1.cc:847
    {}
#line 1063 "binary.tab.cc" // lalr1.cc:847
    break;

  case 62:
#line 213 "binary.yy" // lalr1.cc:847
    {}
#line 1069 "binary.tab.cc" // lalr1.cc:847
    break;

  case 63:
#line 214 "binary.yy" // lalr1.cc:847
    {}
#line 1075 "binary.tab.cc" // lalr1.cc:847
    break;

  case 64:
#line 215 "binary.yy" // lalr1.cc:847
    {}
#line 1081 "binary.tab.cc" // lalr1.cc:847
    break;

  case 65:
#line 216 "binary.yy" // lalr1.cc:847
    {}
#line 1087 "binary.tab.cc" // lalr1.cc:847
    break;

  case 66:
#line 217 "binary.yy" // lalr1.cc:847
    {}
#line 1093 "binary.tab.cc" // lalr1.cc:847
    break;

  case 67:
#line 218 "binary.yy" // lalr1.cc:847
    {}
#line 1099 "binary.tab.cc" // lalr1.cc:847
    break;

  case 68:
#line 219 "binary.yy" // lalr1.cc:847
    {}
#line 1105 "binary.tab.cc" // lalr1.cc:847
    break;

  case 69:
#line 220 "binary.yy" // lalr1.cc:847
    {}
#line 1111 "binary.tab.cc" // lalr1.cc:847
    break;

  case 70:
#line 222 "binary.yy" // lalr1.cc:847
    {}
#line 1117 "binary.tab.cc" // lalr1.cc:847
    break;

  case 71:
#line 223 "binary.yy" // lalr1.cc:847
    {}
#line 1123 "binary.tab.cc" // lalr1.cc:847
    break;

  case 72:
#line 224 "binary.yy" // lalr1.cc:847
    {}
#line 1129 "binary.tab.cc" // lalr1.cc:847
    break;

  case 73:
#line 225 "binary.yy" // lalr1.cc:847
    {}
#line 1135 "binary.tab.cc" // lalr1.cc:847
    break;

  case 74:
#line 228 "binary.yy" // lalr1.cc:847
    {}
#line 1141 "binary.tab.cc" // lalr1.cc:847
    break;

  case 75:
#line 229 "binary.yy" // lalr1.cc:847
    {}
#line 1147 "binary.tab.cc" // lalr1.cc:847
    break;

  case 76:
#line 230 "binary.yy" // lalr1.cc:847
    {}
#line 1153 "binary.tab.cc" // lalr1.cc:847
    break;

  case 77:
#line 233 "binary.yy" // lalr1.cc:847
    {}
#line 1159 "binary.tab.cc" // lalr1.cc:847
    break;

  case 78:
#line 234 "binary.yy" // lalr1.cc:847
    {}
#line 1165 "binary.tab.cc" // lalr1.cc:847
    break;

  case 79:
#line 237 "binary.yy" // lalr1.cc:847
    {}
#line 1171 "binary.tab.cc" // lalr1.cc:847
    break;

  case 80:
#line 238 "binary.yy" // lalr1.cc:847
    {}
#line 1177 "binary.tab.cc" // lalr1.cc:847
    break;

  case 81:
#line 239 "binary.yy" // lalr1.cc:847
    {}
#line 1183 "binary.tab.cc" // lalr1.cc:847
    break;

  case 82:
#line 240 "binary.yy" // lalr1.cc:847
    {}
#line 1189 "binary.tab.cc" // lalr1.cc:847
    break;

  case 83:
#line 243 "binary.yy" // lalr1.cc:847
    {}
#line 1195 "binary.tab.cc" // lalr1.cc:847
    break;

  case 84:
#line 246 "binary.yy" // lalr1.cc:847
    {}
#line 1201 "binary.tab.cc" // lalr1.cc:847
    break;

  case 85:
#line 247 "binary.yy" // lalr1.cc:847
    {}
#line 1207 "binary.tab.cc" // lalr1.cc:847
    break;

  case 86:
#line 250 "binary.yy" // lalr1.cc:847
    {}
#line 1213 "binary.tab.cc" // lalr1.cc:847
    break;

  case 87:
#line 251 "binary.yy" // lalr1.cc:847
    {}
#line 1219 "binary.tab.cc" // lalr1.cc:847
    break;

  case 88:
#line 252 "binary.yy" // lalr1.cc:847
    {}
#line 1225 "binary.tab.cc" // lalr1.cc:847
    break;

  case 89:
#line 255 "binary.yy" // lalr1.cc:847
    {}
#line 1231 "binary.tab.cc" // lalr1.cc:847
    break;

  case 90:
#line 256 "binary.yy" // lalr1.cc:847
    {}
#line 1237 "binary.tab.cc" // lalr1.cc:847
    break;

  case 91:
#line 259 "binary.yy" // lalr1.cc:847
    {}
#line 1243 "binary.tab.cc" // lalr1.cc:847
    break;

  case 92:
#line 260 "binary.yy" // lalr1.cc:847
    {}
#line 1249 "binary.tab.cc" // lalr1.cc:847
    break;

  case 93:
#line 261 "binary.yy" // lalr1.cc:847
    {}
#line 1255 "binary.tab.cc" // lalr1.cc:847
    break;

  case 94:
#line 262 "binary.yy" // lalr1.cc:847
    {}
#line 1261 "binary.tab.cc" // lalr1.cc:847
    break;

  case 95:
#line 265 "binary.yy" // lalr1.cc:847
    {}
#line 1267 "binary.tab.cc" // lalr1.cc:847
    break;

  case 96:
#line 266 "binary.yy" // lalr1.cc:847
    {}
#line 1273 "binary.tab.cc" // lalr1.cc:847
    break;

  case 97:
#line 269 "binary.yy" // lalr1.cc:847
    {}
#line 1279 "binary.tab.cc" // lalr1.cc:847
    break;

  case 98:
#line 270 "binary.yy" // lalr1.cc:847
    {}
#line 1285 "binary.tab.cc" // lalr1.cc:847
    break;

  case 99:
#line 271 "binary.yy" // lalr1.cc:847
    {}
#line 1291 "binary.tab.cc" // lalr1.cc:847
    break;

  case 100:
#line 274 "binary.yy" // lalr1.cc:847
    {}
#line 1297 "binary.tab.cc" // lalr1.cc:847
    break;

  case 101:
#line 275 "binary.yy" // lalr1.cc:847
    {}
#line 1303 "binary.tab.cc" // lalr1.cc:847
    break;

  case 102:
#line 278 "binary.yy" // lalr1.cc:847
    {}
#line 1309 "binary.tab.cc" // lalr1.cc:847
    break;

  case 103:
#line 279 "binary.yy" // lalr1.cc:847
    {}
#line 1315 "binary.tab.cc" // lalr1.cc:847
    break;

  case 104:
#line 280 "binary.yy" // lalr1.cc:847
    {}
#line 1321 "binary.tab.cc" // lalr1.cc:847
    break;

  case 105:
#line 281 "binary.yy" // lalr1.cc:847
    {}
#line 1327 "binary.tab.cc" // lalr1.cc:847
    break;

  case 106:
#line 282 "binary.yy" // lalr1.cc:847
    {}
#line 1333 "binary.tab.cc" // lalr1.cc:847
    break;

  case 107:
#line 283 "binary.yy" // lalr1.cc:847
    {}
#line 1339 "binary.tab.cc" // lalr1.cc:847
    break;

  case 108:
#line 284 "binary.yy" // lalr1.cc:847
    {}
#line 1345 "binary.tab.cc" // lalr1.cc:847
    break;

  case 109:
#line 285 "binary.yy" // lalr1.cc:847
    {}
#line 1351 "binary.tab.cc" // lalr1.cc:847
    break;

  case 110:
#line 286 "binary.yy" // lalr1.cc:847
    {}
#line 1357 "binary.tab.cc" // lalr1.cc:847
    break;

  case 111:
#line 287 "binary.yy" // lalr1.cc:847
    {}
#line 1363 "binary.tab.cc" // lalr1.cc:847
    break;

  case 112:
#line 288 "binary.yy" // lalr1.cc:847
    {}
#line 1369 "binary.tab.cc" // lalr1.cc:847
    break;

  case 113:
#line 289 "binary.yy" // lalr1.cc:847
    {}
#line 1375 "binary.tab.cc" // lalr1.cc:847
    break;

  case 114:
#line 290 "binary.yy" // lalr1.cc:847
    {}
#line 1381 "binary.tab.cc" // lalr1.cc:847
    break;

  case 115:
#line 291 "binary.yy" // lalr1.cc:847
    {}
#line 1387 "binary.tab.cc" // lalr1.cc:847
    break;

  case 116:
#line 292 "binary.yy" // lalr1.cc:847
    {}
#line 1393 "binary.tab.cc" // lalr1.cc:847
    break;

  case 117:
#line 295 "binary.yy" // lalr1.cc:847
    {}
#line 1399 "binary.tab.cc" // lalr1.cc:847
    break;

  case 118:
#line 296 "binary.yy" // lalr1.cc:847
    {}
#line 1405 "binary.tab.cc" // lalr1.cc:847
    break;

  case 119:
#line 297 "binary.yy" // lalr1.cc:847
    {}
#line 1411 "binary.tab.cc" // lalr1.cc:847
    break;


#line 1415 "binary.tab.cc" // lalr1.cc:847
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


  const short int parser::yypact_ninf_ = -129;

  const signed char parser::yytable_ninf_ = -76;

  const short int
  parser::yypact_[] =
  {
      18,  -129,    18,   -43,    -9,   270,    -2,    18,   270,   270,
     270,  -129,    35,  -129,  -129,    18,  -129,    13,    33,    23,
     -13,     7,    34,    54,    26,    70,   -20,    32,  -129,    32,
    -129,  -129,  -129,  -129,  -129,   223,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,    69,   323,   350,  -129,     7,  -129,  -129,
    -129,   278,    48,    44,    55,    84,  -129,   270,    61,   103,
      73,  -129,  -129,    65,  -129,  -129,   270,   -17,    68,    16,
     270,    63,    71,  -129,  -129,  -129,  -129,   270,    76,    77,
     270,    78,    80,     3,    20,  -129,  -129,  -129,   270,    87,
    -129,    95,    57,    18,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,   278,
    -129,    32,   270,   270,    93,  -129,    18,  -129,  -129,  -129,
      41,   -17,  -129,  -129,    94,    91,    98,     4,  -129,    97,
    -129,    96,   142,  -129,  -129,   107,   111,    18,   128,   125,
     270,  -129,  -129,  -129,    57,   104,    89,  -129,  -129,  -129,
    -129,  -129,   165,    45,   101,  -129,  -129,  -129,   270,  -129,
      18,  -129,  -129,   166,    18,   140,  -129,   104,  -129,    18,
     270,  -129,    92,  -129,  -129,     5,   170,  -129,   171,   270,
    -129,   174,   169,    18,   270,  -129,    18,   270,  -129,  -129,
    -129,  -129,    18,   177,   176,   182,   186,  -129,  -129,    18,
    -129,    18,  -129,   197,  -129
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,    34,     4,     0,     0,     0,     0,     4,    32,     0,
       0,    45,     0,     2,     3,     5,     7,     8,    12,     0,
      74,     0,    15,     0,    48,     0,    35,     0,    62,     0,
      61,   118,    63,   117,   119,     0,    66,    70,    71,    72,
      73,    65,    74,     0,     0,    56,    64,    68,    75,    67,
      69,     0,     0,    48,    28,     0,    33,     0,    52,     0,
       0,     1,     6,    10,     9,    13,     0,     0,    42,     0,
       0,     0,     0,    82,    77,    81,    16,     0,     0,    49,
       0,     0,     0,    37,     0,    26,    83,    89,     0,    45,
      99,     0,    91,     4,   115,   116,   102,   103,   104,   105,
     107,   106,   113,   114,   110,   112,   109,   111,   108,    60,
      58,     0,     0,     0,    53,    54,     4,    76,    11,    14,
      74,     0,    79,    88,    86,     0,     0,     0,    47,     0,
      50,     0,     0,    36,    39,     0,     0,     4,     0,     0,
       0,    90,   101,   100,    92,    93,     0,    57,    27,    29,
      18,    55,     0,    74,     0,    80,    46,    78,     0,    51,
       4,    38,    40,     0,     4,     0,    98,    94,    95,     4,
       0,    19,     0,    17,    87,     0,     0,    84,     0,     0,
      96,     0,     0,     4,     0,    21,     4,     0,    25,    85,
      97,    20,     4,     0,     0,     0,     0,    30,    22,     4,
      23,     4,    31,     0,    24
  };

  const short int
  parser::yypgoto_[] =
  {
    -129,  -129,    12,  -129,  -129,   191,   192,  -129,  -129,  -129,
    -129,  -129,  -129,     0,    37,  -129,   -46,  -129,    75,  -129,
     -45,  -129,     1,    11,    81,  -129,   -25,   130,   -16,  -129,
    -129,  -128,    72,  -129,  -129
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,   172,    18,    27,
      83,    19,    68,    42,   124,    79,    56,    57,    58,    44,
      45,    46,    47,    48,    74,    49,    85,   125,    50,    91,
     144,    92,   145,   109,    51
  };

  const short int
  parser::yytable_[] =
  {
      20,    21,    20,    21,    86,    75,   110,    20,    21,    52,
     186,    22,    24,    22,    23,    20,    21,   168,    22,    55,
     119,    10,     1,     2,   -41,    81,    22,    82,     3,     4,
       5,    75,     6,    67,   132,    61,     7,     8,    11,   180,
      25,     9,    69,    54,    35,    69,    26,    35,   135,    70,
     136,   187,    71,    53,    72,   122,    10,    64,    73,   137,
      66,    73,    76,    77,   147,   123,   149,   120,    21,   123,
      84,    53,    78,    11,   -75,    53,   -75,    65,   -43,   -75,
      43,   -75,   -44,    80,    59,    60,   148,   -43,   -75,    93,
      78,   -44,   112,    20,    21,   169,   170,   171,   183,   184,
     185,   142,   143,   111,    22,   146,   113,   115,   116,   118,
      90,    75,   117,    28,   121,    29,    20,    21,   127,    30,
      31,   153,    21,   131,   140,    32,   128,    22,   152,    33,
     155,   130,   114,   133,    34,   134,   141,    20,    21,   151,
     154,   156,    10,   158,    35,   126,    88,   160,    22,   163,
     174,   159,   129,    36,    37,    38,    39,    40,    41,    89,
      20,    21,   161,   139,    20,    21,   162,   164,   165,    20,
      21,    22,   176,   173,   177,    22,   178,   179,   188,   189,
      22,   181,   191,    20,    21,   198,    20,    21,   150,   192,
     200,   201,    20,    21,    22,   193,   199,    22,   195,    20,
      21,    20,    21,    22,   197,   204,    62,    63,   157,     0,
      22,   202,    22,   203,   138,   166,   167,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,   175,    29,     0,     0,     0,    30,    31,
       0,     0,    90,     0,    32,   182,     0,     0,    33,     0,
       0,     0,     0,    34,   190,     0,     0,     0,     0,   194,
       0,    10,   196,    35,    87,    88,     0,     0,     0,     0,
       0,     0,    36,    37,    38,    39,    40,    41,    89,    28,
       0,    29,     0,     0,     0,    30,    31,    28,     0,    29,
       0,    32,     0,    30,     0,    33,     0,     0,     0,    32,
      34,     0,     0,     0,     0,     0,     0,     0,    10,     0,
      35,     0,     0,     0,     0,     0,    10,     0,    35,    36,
      37,    38,    39,    40,    41,    11,    94,    36,    37,    38,
      39,    40,    41,    11,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   -59,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,   -59,     0,     0,
       0,   108,     0,     0,   -59,   -59,   -59,   -59,   -59,   -59,
       0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -59
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,    29,    21,    51,     7,     7,    11,
       5,     0,    55,     2,     2,    15,    15,   145,     7,     7,
      66,    38,     4,     5,    37,    45,    15,    47,    10,    11,
      12,    47,    14,    46,    80,     0,    18,    19,    55,   167,
       3,    23,    38,     6,    40,    38,    55,    40,    45,    42,
      47,    46,    45,    55,    47,    39,    38,    44,    54,    39,
      37,    54,     8,    37,   109,    49,   112,    67,    67,    49,
      38,    55,    46,    55,    40,    55,    42,    44,    37,    45,
       5,    47,    37,    13,     9,    10,   111,    46,    54,    20,
      46,    46,    37,    93,    93,     6,     7,     8,     6,     7,
       8,    44,    45,    55,    93,    93,    22,    46,     5,    44,
      35,   127,    39,     9,    46,    11,   116,   116,    55,    15,
      16,   121,   121,    46,    37,    21,    55,   116,   116,    25,
      39,    55,    57,    55,    30,    55,    41,   137,   137,    46,
      46,    43,    38,    46,    40,    70,    42,     5,   137,   137,
      49,    55,    77,    49,    50,    51,    52,    53,    54,    55,
     160,   160,    55,    88,   164,   164,    55,    39,    43,   169,
     169,   160,   160,     8,     8,   164,   164,    37,     8,     8,
     169,   169,     8,   183,   183,     8,   186,   186,   113,    20,
       8,     5,   192,   192,   183,   183,    20,   186,   186,   199,
     199,   201,   201,   192,   192,     8,    15,    15,   127,    -1,
     199,   199,   201,   201,    84,   140,   144,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,   158,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,   167,    -1,    21,   170,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,   179,    -1,    -1,    -1,    -1,   184,
      -1,    38,   187,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,     9,
      -1,    11,    -1,    -1,    -1,    15,    16,     9,    -1,    11,
      -1,    21,    -1,    15,    -1,    25,    -1,    -1,    -1,    21,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    49,
      50,    51,    52,    53,    54,    55,     3,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,     3,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    48,    -1,    -1,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     5,    10,    11,    12,    14,    18,    19,    23,
      38,    55,    57,    58,    59,    60,    61,    62,    64,    67,
      69,    78,    79,    58,    55,    70,    55,    65,     9,    11,
      15,    16,    21,    25,    30,    40,    49,    50,    51,    52,
      53,    54,    69,    74,    75,    76,    77,    78,    79,    81,
      84,    90,    11,    55,    70,    58,    72,    73,    74,    74,
      74,     0,    61,    62,    44,    44,    37,    46,    68,    38,
      42,    45,    47,    54,    80,    84,     8,    37,    46,    71,
      13,    45,    47,    66,    38,    82,    82,    41,    42,    55,
      74,    85,    87,    20,     3,    17,    24,    25,    26,    27,
      28,    29,    31,    32,    33,    34,    35,    36,    48,    89,
      76,    55,    37,    22,    74,    46,     5,    39,    44,    72,
      69,    46,    39,    49,    70,    83,    74,    55,    55,    74,
      55,    46,    72,    55,    55,    45,    47,    39,    83,    74,
      37,    41,    44,    45,    86,    88,    58,    76,    82,    72,
      74,    46,    58,    69,    46,    39,    43,    80,    46,    55,
       5,    55,    55,    58,    39,    43,    74,    88,    87,     6,
       7,     8,    63,     8,    49,    74,    58,     8,    58,    37,
      87,    58,    74,     6,     7,     8,     5,    46,     8,     8,
      74,     8,    20,    58,    74,    58,    74,    58,     8,    20,
       8,     5,    58,    58,     8
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
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    90
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
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     4,     2,
       3,     1,     1,     2,     4,     5,     1,     3,     1,     2,
       3,     1,     2,     2,     3,     2,     3,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "DOTDOTDOT", "INTEGER", "DECIMAL", "POWEROF", "HEXADECIMAL", "String",
  "Name", "$accept", "S", "block", "chunk", "chunk_layer",
  "laststat_layer", "stat", "elseif_layer", "laststat", "funcname",
  "funcname_layer", "varlist", "varlist_layer", "var", "namelist",
  "namelist_layer", "explist", "explist_layer", "exp", "exp_rec",
  "exp_layer", "Number", "prefixexp", "functioncall", "args", "function",
  "funcbody", "parlist", "tableconstructor", "fieldlist",
  "fieldlist_layer", "field", "fieldsep", "binop", "unop", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   115,   115,   118,   121,   122,   123,   124,   127,   128,
     129,   130,   133,   134,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     156,   157,   160,   161,   162,   164,   165,   166,   167,   170,
     171,   174,   175,   178,   179,   182,   183,   184,   187,   188,
     191,   192,   195,   196,   199,   200,   204,   205,   206,   209,
     210,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     222,   223,   224,   225,   228,   229,   230,   233,   234,   237,
     238,   239,   240,   243,   246,   247,   250,   251,   252,   255,
     256,   259,   260,   261,   262,   265,   266,   269,   270,   271,
     274,   275,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   295,   296,   297
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
#line 1876 "binary.tab.cc" // lalr1.cc:1155
