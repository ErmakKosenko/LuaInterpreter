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
	int nameCounter = 0;
	list<BBlock> Node::blocks(root.initBBlockList());
	#define YY_DECL yy::parser::symbol_type yylex()
	YY_DECL;

#line 61 "binary.tab.cc" // lalr1.cc:408


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
#line 128 "binary.tab.cc" // lalr1.cc:474

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
#line 125 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("start", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); root = yylhs.value.as< Node > (); }
#line 725 "binary.tab.cc" // lalr1.cc:847
    break;

  case 3:
#line 128 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 731 "binary.tab.cc" // lalr1.cc:847
    break;

  case 4:
#line 131 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("block", "empty"); }
#line 737 "binary.tab.cc" // lalr1.cc:847
    break;

  case 5:
#line 132 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 743 "binary.tab.cc" // lalr1.cc:847
    break;

  case 6:
#line 133 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 749 "binary.tab.cc" // lalr1.cc:847
    break;

  case 7:
#line 134 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("block", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 755 "binary.tab.cc" // lalr1.cc:847
    break;

  case 8:
#line 137 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statementchunk",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 761 "binary.tab.cc" // lalr1.cc:847
    break;

  case 9:
#line 138 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statementchunk",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("semicolon",";")); }
#line 767 "binary.tab.cc" // lalr1.cc:847
    break;

  case 10:
#line 139 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statementchunk",""); for(Node e : yystack_[1].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());  }
#line 773 "binary.tab.cc" // lalr1.cc:847
    break;

  case 11:
#line 140 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statementchunk",""); for(Node e : yystack_[2].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("semicolon",";")); }
#line 779 "binary.tab.cc" // lalr1.cc:847
    break;

  case 12:
#line 143 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 785 "binary.tab.cc" // lalr1.cc:847
    break;

  case 13:
#line 144 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[1].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("semicolon",";")); }
#line 791 "binary.tab.cc" // lalr1.cc:847
    break;

  case 14:
#line 148 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement", ""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 797 "binary.tab.cc" // lalr1.cc:847
    break;

  case 15:
#line 149 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 803 "binary.tab.cc" // lalr1.cc:847
    break;

  case 16:
#line 150 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 809 "binary.tab.cc" // lalr1.cc:847
    break;

  case 17:
#line 151 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("while","while")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 815 "binary.tab.cc" // lalr1.cc:847
    break;

  case 18:
#line 152 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("repeat", "")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("until", "")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 821 "binary.tab.cc" // lalr1.cc:847
    break;

  case 19:
#line 153 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 827 "binary.tab.cc" // lalr1.cc:847
    break;

  case 20:
#line 154 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("else","else")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 833 "binary.tab.cc" // lalr1.cc:847
    break;

  case 21:
#line 155 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("elseif","elseif")); for(Node e : yystack_[1].value.as< Node > ().children) {yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 839 "binary.tab.cc" // lalr1.cc:847
    break;

  case 22:
#line 156 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("if","if")); yylhs.value.as< Node > ().children.push_back(yystack_[6].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("elseif","elseif")); for(Node e : yystack_[3].value.as< Node > ().children) {yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(Node("else","else")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 845 "binary.tab.cc" // lalr1.cc:847
    break;

  case 23:
#line 157 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("for","for")); yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 851 "binary.tab.cc" // lalr1.cc:847
    break;

  case 24:
#line 158 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("for","for")); yylhs.value.as< Node > ().children.push_back(yystack_[9].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[7].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 857 "binary.tab.cc" // lalr1.cc:847
    break;

  case 25:
#line 159 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("for","for")); yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("in","in")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("do","do")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 863 "binary.tab.cc" // lalr1.cc:847
    break;

  case 26:
#line 160 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("function","function")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 869 "binary.tab.cc" // lalr1.cc:847
    break;

  case 27:
#line 161 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("local","local")); yylhs.value.as< Node > ().children.push_back(Node("function","function")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 875 "binary.tab.cc" // lalr1.cc:847
    break;

  case 28:
#line 162 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("local","local")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 881 "binary.tab.cc" // lalr1.cc:847
    break;

  case 29:
#line 163 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("statement",""); yylhs.value.as< Node > ().children.push_back(Node("local","local")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 887 "binary.tab.cc" // lalr1.cc:847
    break;

  case 30:
#line 166 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("elseif","elseif"); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 893 "binary.tab.cc" // lalr1.cc:847
    break;

  case 31:
#line 167 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[4].value.as< Node > ();  yylhs.value.as< Node > ().children.push_back(Node("elseif","elseif")); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("then","then")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 899 "binary.tab.cc" // lalr1.cc:847
    break;

  case 32:
#line 170 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("laststatement",""); yylhs.value.as< Node > ().children.push_back(Node("return","return")); }
#line 905 "binary.tab.cc" // lalr1.cc:847
    break;

  case 33:
#line 171 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("laststatement",""); yylhs.value.as< Node > ().children.push_back(Node("return","return")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 911 "binary.tab.cc" // lalr1.cc:847
    break;

  case 34:
#line 172 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("laststatement",""); yylhs.value.as< Node > ().children.push_back(Node("break","break")); }
#line 917 "binary.tab.cc" // lalr1.cc:847
    break;

  case 35:
#line 174 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 923 "binary.tab.cc" // lalr1.cc:847
    break;

  case 36:
#line 175 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("colon",":")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 929 "binary.tab.cc" // lalr1.cc:847
    break;

  case 37:
#line 176 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} 	}
#line 935 "binary.tab.cc" // lalr1.cc:847
    break;

  case 38:
#line 177 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcname",""); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); for(Node e : yystack_[2].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(Node("colon",":")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 941 "binary.tab.cc" // lalr1.cc:847
    break;

  case 39:
#line 180 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("dot","."); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 947 "binary.tab.cc" // lalr1.cc:847
    break;

  case 40:
#line 181 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("dot",".")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 953 "binary.tab.cc" // lalr1.cc:847
    break;

  case 41:
#line 184 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("varlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 959 "binary.tab.cc" // lalr1.cc:847
    break;

  case 42:
#line 185 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("varlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} }
#line 965 "binary.tab.cc" // lalr1.cc:847
    break;

  case 43:
#line 188 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("comma",","); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 971 "binary.tab.cc" // lalr1.cc:847
    break;

  case 44:
#line 189 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 977 "binary.tab.cc" // lalr1.cc:847
    break;

  case 45:
#line 192 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("var",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 983 "binary.tab.cc" // lalr1.cc:847
    break;

  case 46:
#line 193 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("var",""); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("leftbracket","[")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightbracket","]")); }
#line 989 "binary.tab.cc" // lalr1.cc:847
    break;

  case 47:
#line 194 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("var",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("dot",".")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 995 "binary.tab.cc" // lalr1.cc:847
    break;

  case 48:
#line 197 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("namelist", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1001 "binary.tab.cc" // lalr1.cc:847
    break;

  case 49:
#line 198 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("namelist", ""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} }
#line 1007 "binary.tab.cc" // lalr1.cc:847
    break;

  case 50:
#line 201 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("namelist_layer",""); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1013 "binary.tab.cc" // lalr1.cc:847
    break;

  case 51:
#line 202 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1019 "binary.tab.cc" // lalr1.cc:847
    break;

  case 52:
#line 205 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("explist", ""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1025 "binary.tab.cc" // lalr1.cc:847
    break;

  case 53:
#line 206 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("explist", ""); for(Node e: yystack_[1].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1031 "binary.tab.cc" // lalr1.cc:847
    break;

  case 54:
#line 209 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("explist_layer",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); }
#line 1037 "binary.tab.cc" // lalr1.cc:847
    break;

  case 55:
#line 210 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); }
#line 1043 "binary.tab.cc" // lalr1.cc:847
    break;

  case 56:
#line 213 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("exp",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1049 "binary.tab.cc" // lalr1.cc:847
    break;

  case 57:
#line 214 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("exp",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1055 "binary.tab.cc" // lalr1.cc:847
    break;

  case 58:
#line 215 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); }
#line 1061 "binary.tab.cc" // lalr1.cc:847
    break;

  case 59:
#line 216 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); yylhs.value.as< Node > ().children.push_front(Node("unop",yystack_[1].value.as< std::string > ())); }
#line 1067 "binary.tab.cc" // lalr1.cc:847
    break;

  case 60:
#line 217 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); yylhs.value.as< Node > ().children.push_front(Node("unop",yystack_[1].value.as< std::string > ())); }
#line 1073 "binary.tab.cc" // lalr1.cc:847
    break;

  case 61:
#line 218 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); yylhs.value.as< Node > ().children.push_front(Node("unop",yystack_[1].value.as< std::string > ())); }
#line 1079 "binary.tab.cc" // lalr1.cc:847
    break;

  case 62:
#line 221 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1085 "binary.tab.cc" // lalr1.cc:847
    break;

  case 63:
#line 222 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1091 "binary.tab.cc" // lalr1.cc:847
    break;

  case 64:
#line 223 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1097 "binary.tab.cc" // lalr1.cc:847
    break;

  case 65:
#line 224 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1103 "binary.tab.cc" // lalr1.cc:847
    break;

  case 66:
#line 225 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1109 "binary.tab.cc" // lalr1.cc:847
    break;

  case 67:
#line 226 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1115 "binary.tab.cc" // lalr1.cc:847
    break;

  case 68:
#line 227 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1121 "binary.tab.cc" // lalr1.cc:847
    break;

  case 69:
#line 228 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1127 "binary.tab.cc" // lalr1.cc:847
    break;

  case 70:
#line 229 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1133 "binary.tab.cc" // lalr1.cc:847
    break;

  case 71:
#line 230 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1139 "binary.tab.cc" // lalr1.cc:847
    break;

  case 72:
#line 231 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1145 "binary.tab.cc" // lalr1.cc:847
    break;

  case 73:
#line 232 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1151 "binary.tab.cc" // lalr1.cc:847
    break;

  case 74:
#line 233 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("binop",yystack_[1].value.as< std::string > ())); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1157 "binary.tab.cc" // lalr1.cc:847
    break;

  case 75:
#line 234 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("term",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1163 "binary.tab.cc" // lalr1.cc:847
    break;

  case 76:
#line 237 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("nil",yystack_[0].value.as< std::string > ());}
#line 1169 "binary.tab.cc" // lalr1.cc:847
    break;

  case 77:
#line 238 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("false",yystack_[0].value.as< std::string > ());}
#line 1175 "binary.tab.cc" // lalr1.cc:847
    break;

  case 78:
#line 239 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("true",yystack_[0].value.as< std::string > ());}
#line 1181 "binary.tab.cc" // lalr1.cc:847
    break;

  case 79:
#line 240 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1187 "binary.tab.cc" // lalr1.cc:847
    break;

  case 80:
#line 241 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1193 "binary.tab.cc" // lalr1.cc:847
    break;

  case 81:
#line 242 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("dotdotdot",yystack_[0].value.as< std::string > ());}
#line 1199 "binary.tab.cc" // lalr1.cc:847
    break;

  case 82:
#line 243 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1205 "binary.tab.cc" // lalr1.cc:847
    break;

  case 83:
#line 244 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1211 "binary.tab.cc" // lalr1.cc:847
    break;

  case 84:
#line 245 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1217 "binary.tab.cc" // lalr1.cc:847
    break;

  case 85:
#line 249 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("integer", yystack_[0].value.as< std::string > ()); }
#line 1223 "binary.tab.cc" // lalr1.cc:847
    break;

  case 86:
#line 250 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("decimal", yystack_[0].value.as< std::string > ());}
#line 1229 "binary.tab.cc" // lalr1.cc:847
    break;

  case 87:
#line 251 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("powerof", yystack_[0].value.as< std::string > ());}
#line 1235 "binary.tab.cc" // lalr1.cc:847
    break;

  case 88:
#line 252 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("hexadecimal", yystack_[0].value.as< std::string > ());}
#line 1241 "binary.tab.cc" // lalr1.cc:847
    break;

  case 89:
#line 255 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("identifier", yystack_[0].value.as< std::string > ()); }
#line 1247 "binary.tab.cc" // lalr1.cc:847
    break;

  case 90:
#line 258 "binary.yy" // lalr1.cc:847
    { std::string temp; for(int i=1;i<yystack_[0].value.as< std::string > ().length()-1;i++){temp = temp + yystack_[0].value.as< std::string > ()[i];}  yylhs.value.as< Node > () = Node("string",temp);}
#line 1253 "binary.tab.cc" // lalr1.cc:847
    break;

  case 91:
#line 261 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("prefixexp",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1259 "binary.tab.cc" // lalr1.cc:847
    break;

  case 92:
#line 262 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("prefixexp",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1265 "binary.tab.cc" // lalr1.cc:847
    break;

  case 93:
#line 263 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("prefixexp",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(Node(yystack_[1].value.as< Node > ())); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); }
#line 1271 "binary.tab.cc" // lalr1.cc:847
    break;

  case 94:
#line 266 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("functioncall",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1277 "binary.tab.cc" // lalr1.cc:847
    break;

  case 95:
#line 267 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("functioncall",""); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("colon",":")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1283 "binary.tab.cc" // lalr1.cc:847
    break;

  case 96:
#line 270 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); }
#line 1289 "binary.tab.cc" // lalr1.cc:847
    break;

  case 97:
#line 271 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")"));}
#line 1295 "binary.tab.cc" // lalr1.cc:847
    break;

  case 98:
#line 272 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1301 "binary.tab.cc" // lalr1.cc:847
    break;

  case 99:
#line 273 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("args",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1307 "binary.tab.cc" // lalr1.cc:847
    break;

  case 100:
#line 276 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("function","function"); yylhs.value.as< Node > ().children.push_back(Node("function","function")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1313 "binary.tab.cc" // lalr1.cc:847
    break;

  case 101:
#line 279 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end")); }
#line 1319 "binary.tab.cc" // lalr1.cc:847
    break;

  case 102:
#line 280 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(Node("leftparentheses","(")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightparentheses",")")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("end","end"));}
#line 1325 "binary.tab.cc" // lalr1.cc:847
    break;

  case 103:
#line 283 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1331 "binary.tab.cc" // lalr1.cc:847
    break;

  case 104:
#line 284 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("comma",",")); yylhs.value.as< Node > ().children.push_back(Node("dotdotdot","...")); }
#line 1337 "binary.tab.cc" // lalr1.cc:847
    break;

  case 105:
#line 285 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("funcbody",""); yylhs.value.as< Node > ().children.push_back(Node("dotdotdot","..."));}
#line 1343 "binary.tab.cc" // lalr1.cc:847
    break;

  case 106:
#line 288 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("tableconstructor",""); yylhs.value.as< Node > ().children.push_back(Node("leftbraces","[")); yylhs.value.as< Node > ().children.push_back(Node("rightbraces","]")); }
#line 1349 "binary.tab.cc" // lalr1.cc:847
    break;

  case 107:
#line 289 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("tableconstructor",""); yylhs.value.as< Node > ().children.push_back(Node("leftbraces","[")); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightbraces","]"));}
#line 1355 "binary.tab.cc" // lalr1.cc:847
    break;

  case 108:
#line 292 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1361 "binary.tab.cc" // lalr1.cc:847
    break;

  case 109:
#line 293 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); for(Node e : yystack_[0].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);}}
#line 1367 "binary.tab.cc" // lalr1.cc:847
    break;

  case 110:
#line 294 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1373 "binary.tab.cc" // lalr1.cc:847
    break;

  case 111:
#line 295 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); for(Node e : yystack_[1].value.as< Node > ().children){yylhs.value.as< Node > ().children.push_back(e);} yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1379 "binary.tab.cc" // lalr1.cc:847
    break;

  case 112:
#line 298 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("fieldlist_layer",""); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1385 "binary.tab.cc" // lalr1.cc:847
    break;

  case 113:
#line 299 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = yystack_[2].value.as< Node > (); yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1391 "binary.tab.cc" // lalr1.cc:847
    break;

  case 114:
#line 302 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("field",""); yylhs.value.as< Node > ().children.push_back(Node("leftbracket","[")); yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("rightbracket","]")); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1397 "binary.tab.cc" // lalr1.cc:847
    break;

  case 115:
#line 303 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("field",""); yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); yylhs.value.as< Node > ().children.push_back(Node("equal","=")); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); }
#line 1403 "binary.tab.cc" // lalr1.cc:847
    break;

  case 116:
#line 304 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("field",""); yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());}
#line 1409 "binary.tab.cc" // lalr1.cc:847
    break;

  case 117:
#line 307 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Fieldsep", yystack_[0].value.as< std::string > ());}
#line 1415 "binary.tab.cc" // lalr1.cc:847
    break;

  case 118:
#line 308 "binary.yy" // lalr1.cc:847
    { yylhs.value.as< Node > () = Node("Fieldsep", yystack_[0].value.as< std::string > ());}
#line 1421 "binary.tab.cc" // lalr1.cc:847
    break;


#line 1425 "binary.tab.cc" // lalr1.cc:847
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


  const short int parser::yypact_ninf_ = -134;

  const signed char parser::yytable_ninf_ = -93;

  const short int
  parser::yypact_[] =
  {
      34,  -134,    34,   -36,   -36,   385,    -1,    34,   385,   385,
     385,  -134,    24,  -134,  -134,    34,  -134,     3,    19,   -10,
     -15,  -134,   122,   193,    47,    63,   -12,    41,    59,  -134,
      41,  -134,   385,  -134,   385,   385,   241,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,    92,   123,  -134,  -134,  -134,   122,
    -134,  -134,  -134,   -36,    70,    48,    81,  -134,   385,    12,
      18,    66,  -134,  -134,    84,  -134,  -134,   385,   -26,    93,
     291,   385,   -36,   -36,  -134,  -134,  -134,  -134,   385,   385,
     -36,   102,    10,  -134,   -36,   -36,    91,  -134,  -134,  -134,
    -134,  -134,   385,    89,    98,   112,   101,    34,   393,   393,
     393,   393,   393,   393,   393,   393,   393,   393,   393,   393,
     393,   393,   393,    41,   385,   385,    42,  -134,    34,  -134,
    -134,  -134,    38,   -26,  -134,   124,    53,    61,  -134,   160,
      49,  -134,   -36,    34,  -134,   126,   129,  -134,  -134,   -36,
     -36,    57,   385,  -134,  -134,  -134,   101,   338,   174,   123,
     123,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,    89,  -134,   162,    56,
    -134,  -134,  -134,    34,   385,  -134,   167,   128,    34,  -134,
    -134,   146,    89,   338,  -134,    34,   385,  -134,   214,  -134,
     179,    16,  -134,  -134,   180,   385,  -134,   182,   107,    34,
     385,  -134,  -134,    34,   385,  -134,    89,  -134,    34,   187,
     117,   189,    46,  -134,  -134,    34,  -134,    34,  -134,   194,
    -134
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,    34,     4,     0,     0,     0,     0,     4,    32,     0,
       0,    89,     0,     2,     3,     5,     7,     8,    12,     0,
      91,    45,     0,    15,     0,     0,    48,     0,    35,    77,
       0,    76,     0,    78,     0,     0,     0,    81,    85,    86,
      87,    88,    90,    91,     0,    58,    75,    79,    80,    83,
      92,    82,    84,     0,    28,    48,     0,    33,     0,    52,
       0,     0,     1,     6,    10,     9,    13,     0,     0,    42,
       0,     0,     0,     0,    99,    94,    98,    16,     0,     0,
       0,    49,     0,    26,     0,     0,    37,   100,    60,    59,
      61,   106,     0,   116,    45,     0,   108,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,     4,    93,
      11,    14,    91,     0,    96,     0,     0,     0,    47,     0,
       0,    50,     0,     4,   105,   103,     0,    36,    39,     0,
       0,     0,     0,   107,   118,   117,   109,   110,     0,    56,
      57,    73,    74,    62,    63,    64,    65,    71,    72,    68,
      70,    67,    69,    66,    27,    29,    18,    55,     0,    91,
      97,    46,    95,     4,     0,    51,     0,     0,     4,    38,
      40,     0,   115,   111,   112,     4,     0,    19,     0,    17,
       0,     0,   101,   104,     0,     0,   113,     0,     0,     4,
       0,    21,    25,     4,     0,   102,   114,    20,     4,     0,
       0,     0,     0,    30,    22,     4,    23,     4,    31,     0,
      24
  };

  const short int
  parser::yypgoto_[] =
  {
    -134,  -134,    28,  -134,  -134,   190,   192,  -134,  -134,  -134,
    -134,  -134,  -134,     0,    -2,  -134,   -50,  -134,    51,    22,
     349,  -134,   188,   -17,     1,    11,    85,  -134,   -21,  -134,
     -16,  -134,  -134,  -133,    65
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,    17,   188,    18,    27,
      86,    19,    69,    43,    25,    81,    57,    58,    59,    45,
      46,    47,    21,    48,    49,    50,    75,    51,    83,   136,
      52,    95,   146,    96,   147
  };

  const short int
  parser::yytable_[] =
  {
      20,    22,    20,    22,    54,    74,    76,    20,    22,    87,
      53,    23,    10,    23,   184,    20,    22,   121,    23,    11,
     125,   203,   -41,   118,    62,    79,    23,    67,   129,    11,
      24,    68,    74,    76,    80,    56,    98,    99,     1,     2,
      98,    99,    98,    99,     3,     4,     5,    65,     6,   133,
     196,   217,     7,     8,    11,    77,    44,     9,   117,   134,
      60,    61,   204,    66,   165,    11,    98,    99,   122,    22,
      98,    99,    10,    98,    99,   -43,    78,    98,    99,    82,
     135,    98,    99,    88,   -43,    89,    90,    93,   167,    11,
      98,    99,   164,   -44,    80,   174,   171,    20,    22,    70,
     181,    36,   -44,   115,    84,   119,    85,   114,    23,   116,
      74,    76,    97,    98,    99,    42,    98,    99,    20,    22,
     149,   150,   126,   169,    22,   148,   100,   208,   120,    23,
     130,    98,    99,    20,    22,   142,   139,   215,   140,   123,
     101,    98,    99,   141,    23,   144,   168,   145,   132,   102,
     103,   104,   105,   143,   106,   107,   108,   109,   110,   111,
      70,   176,    36,   170,    71,   173,   166,    72,   178,    73,
     189,   112,   177,    20,    22,   192,    42,   193,    20,    22,
     185,   186,   187,   195,    23,    20,    22,   202,   205,    23,
     207,    26,    28,   182,    55,   214,    23,   216,    93,    20,
      22,   190,   220,    20,    22,    63,   194,    64,    20,    22,
      23,   183,   172,   197,    23,    20,    22,    20,    22,    23,
     199,   200,   201,     0,    94,   191,    23,   209,    23,     0,
       0,   211,     0,   -92,    93,   -92,   213,   198,   -92,     0,
     -92,   113,     0,   218,     0,   219,   206,   -92,     0,     0,
      29,   210,    30,     0,     0,   212,    31,    32,     0,     0,
     127,   128,    33,     0,     0,     0,    34,     0,   131,     0,
      55,    35,   137,   138,     0,     0,     0,     0,     0,    10,
       0,    36,    91,    92,     0,     0,     0,     0,     0,     0,
      37,    38,    39,    40,    41,    42,    11,     0,     0,     0,
      29,     0,    30,     0,     0,     0,    31,    32,     0,     0,
       0,     0,    33,     0,     0,     0,    34,     0,     0,     0,
     175,    35,     0,     0,     0,     0,     0,   179,   180,    10,
     124,    36,     0,     0,     0,    94,     0,     0,     0,     0,
      37,    38,    39,    40,    41,    42,    11,    29,     0,    30,
       0,     0,     0,    31,    32,     0,     0,     0,     0,    33,
       0,     0,     0,    34,     0,     0,     0,     0,    35,     0,
       0,    94,     0,     0,     0,     0,    10,     0,    36,     0,
      92,     0,     0,     0,     0,     0,     0,    37,    38,    39,
      40,    41,    42,    11,    29,     0,    30,     0,     0,     0,
      31,    32,    29,     0,    30,     0,    33,     0,    31,     0,
      34,     0,     0,     0,    33,    35,     0,     0,     0,     0,
       0,     0,     0,    10,     0,    36,     0,     0,     0,     0,
       0,    10,     0,    36,    37,    38,    39,    40,    41,    42,
      11,     0,    37,    38,    39,    40,    41,    42,    11,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,     2,     2,     6,    22,    22,     7,     7,    30,
      11,     0,    38,     2,   147,    15,    15,    67,     7,    55,
      70,     5,    37,     5,     0,    37,    15,    37,    78,    55,
       2,    46,    49,    49,    46,     7,    24,    25,     4,     5,
      24,    25,    24,    25,    10,    11,    12,    44,    14,    39,
     183,     5,    18,    19,    55,     8,     5,    23,    46,    49,
       9,    10,    46,    44,   114,    55,    24,    25,    68,    68,
      24,    25,    38,    24,    25,    37,    13,    24,    25,    38,
      82,    24,    25,    32,    46,    34,    35,    36,    46,    55,
      24,    25,   113,    37,    46,    46,    43,    97,    97,    38,
      43,    40,    46,    22,    45,    39,    47,    37,    97,    58,
     127,   127,    20,    24,    25,    54,    24,    25,   118,   118,
      98,    99,    71,   123,   123,    97,     3,    20,    44,   118,
      79,    24,    25,   133,   133,    37,    45,    20,    47,    46,
      17,    24,    25,    92,   133,    44,   118,    46,    46,    26,
      27,    28,    29,    41,    31,    32,    33,    34,    35,    36,
      38,   133,    40,    39,    42,     5,   115,    45,    39,    47,
       8,    48,    46,   173,   173,     8,    54,    49,   178,   178,
       6,     7,     8,    37,   173,   185,   185,     8,     8,   178,
       8,     3,     4,   142,     6,     8,   185,     8,   147,   199,
     199,   173,     8,   203,   203,    15,   178,    15,   208,   208,
     199,   146,   127,   185,   203,   215,   215,   217,   217,   208,
       6,     7,     8,    -1,    36,   174,   215,   199,   217,    -1,
      -1,   203,    -1,    40,   183,    42,   208,   186,    45,    -1,
      47,    53,    -1,   215,    -1,   217,   195,    54,    -1,    -1,
       9,   200,    11,    -1,    -1,   204,    15,    16,    -1,    -1,
      72,    73,    21,    -1,    -1,    -1,    25,    -1,    80,    -1,
      82,    30,    84,    85,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
       9,    -1,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
     132,    30,    -1,    -1,    -1,    -1,    -1,   139,   140,    38,
      39,    40,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,     9,    -1,    11,
      -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    38,    -1,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,     9,    -1,    11,    -1,    -1,    -1,
      15,    16,     9,    -1,    11,    -1,    21,    -1,    15,    -1,
      25,    -1,    -1,    -1,    21,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    49,    50,    51,    52,    53,    54,
      55,    -1,    49,    50,    51,    52,    53,    54,    55,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,     5,    10,    11,    12,    14,    18,    19,    23,
      38,    55,    57,    58,    59,    60,    61,    62,    64,    67,
      69,    78,    80,    81,    58,    70,    78,    65,    78,     9,
      11,    15,    16,    21,    25,    30,    40,    49,    50,    51,
      52,    53,    54,    69,    74,    75,    76,    77,    79,    80,
      81,    83,    86,    11,    70,    78,    58,    72,    73,    74,
      74,    74,     0,    61,    62,    44,    44,    37,    46,    68,
      38,    42,    45,    47,    79,    82,    86,     8,    13,    37,
      46,    71,    38,    84,    45,    47,    66,    84,    74,    74,
      74,    41,    42,    74,    78,    87,    89,    20,    24,    25,
       3,    17,    26,    27,    28,    29,    31,    32,    33,    34,
      35,    36,    48,    78,    37,    22,    74,    46,     5,    39,
      44,    72,    69,    46,    39,    72,    74,    78,    78,    72,
      74,    78,    46,    39,    49,    70,    85,    78,    78,    45,
      47,    74,    37,    41,    44,    46,    88,    90,    58,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    84,    72,    74,    46,    58,    69,
      39,    43,    82,     5,    46,    78,    58,    46,    39,    78,
      78,    43,    74,    90,    89,     6,     7,     8,    63,     8,
      58,    74,     8,    49,    58,    37,    89,    58,    74,     6,
       7,     8,     8,     5,    46,     8,    74,     8,    20,    58,
      74,    58,    74,    58,     8,    20,     8,     5,    58,    58,
       8
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    56,    57,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    78,
      79,    80,    80,    80,    81,    81,    82,    82,    82,    82,
      83,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      87,    87,    88,    88,    89,    89,    89,    90,    90
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     0,     1,     2,     1,     1,     2,
       2,     3,     1,     2,     3,     1,     3,     5,     4,     5,
       7,     6,     8,     9,    11,     7,     3,     4,     2,     4,
       4,     5,     1,     2,     1,     1,     3,     2,     4,     2,
       3,     1,     2,     2,     3,     1,     4,     3,     1,     2,
       2,     3,     1,     2,     2,     3,     3,     3,     1,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     4,     2,     3,     1,     1,
       2,     4,     5,     1,     3,     1,     2,     3,     1,     2,
       2,     3,     2,     3,     5,     3,     1,     1,     1
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
  "PLUS", "MINUS", "MULTIPLY", "DEVIDE", "PERCENT", "CARET", "HASHTAG",
  "EQUALTO", "TILDEEQUAL", "LESSOREQUAL", "GREATEROREQUAL", "LESSTHAN",
  "GREATERTHAN", "EQUAL", "LEFTPARENTHESES", "RIGHTPARENTHESES",
  "LEFTBRACES", "RIGHTBRACES", "LEFTBRACKET", "RIGHTBRACKET", "SEMICOLON",
  "COLON", "COMMA", "DOT", "DOTDOT", "DOTDOTDOT", "INTEGER", "DECIMAL",
  "POWEROF", "HEXADECIMAL", "STRING", "NAME", "$accept", "S", "block",
  "chunk", "chunk_layer", "laststat_layer", "stat", "elseif_layer",
  "laststat", "funcname", "funcname_layer", "varlist", "varlist_layer",
  "var", "namelist", "namelist_layer", "explist", "explist_layer", "exp",
  "term", "exp_layer", "Number", "Name", "String", "prefixexp",
  "functioncall", "args", "function", "funcbody", "parlist",
  "tableconstructor", "fieldlist", "fieldlist_layer", "field", "fieldsep", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   125,   125,   128,   131,   132,   133,   134,   137,   138,
     139,   140,   143,   144,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     166,   167,   170,   171,   172,   174,   175,   176,   177,   180,
     181,   184,   185,   188,   189,   192,   193,   194,   197,   198,
     201,   202,   205,   206,   209,   210,   213,   214,   215,   216,
     217,   218,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   249,   250,   251,   252,   255,
     258,   261,   262,   263,   266,   267,   270,   271,   272,   273,
     276,   279,   280,   283,   284,   285,   288,   289,   292,   293,
     294,   295,   298,   299,   302,   303,   304,   307,   308
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
#line 1905 "binary.tab.cc" // lalr1.cc:1155