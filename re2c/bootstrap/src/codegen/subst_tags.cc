/* Generated by re2c 0.16 on Fri May 13 13:49:35 2016 */
#line 1 "../src/codegen/subst_tags.re"
#include "src/codegen/emit.h"
#include "src/codegen/input_api.h"
#include "src/conf/opt.h"
#include "src/globals.h"

namespace re2c
{

std::string subst_tags(const std::string &action,
	const std::valarray<Tag> &tags, size_t ltag, size_t htag)
{
	if (ltag >= htag) {
		return action;
	}

	std::string result;
	const char
		*head = action.c_str(),
		*last = head + action.length(),
		*tail = head,
		*base;

	loop: 
#line 27 "src/codegen/subst_tags.cc"
{
	char yych;
	long yytag1name;
	static const unsigned char yybm[] = {
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128,   0,   0,   0,   0,   0,   0, 
		  0, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128,   0,   0,   0,   0, 128, 
		  0, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128, 128,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	base = head;
	yych = *head;
	if (yych <= 0x00) goto yy2;
	if (yych == '@') goto yy6;
	goto yy4;
yy2:
	++head;
#line 33 "../src/codegen/subst_tags.re"
	{
			if (base == last) {
				result.append(tail, base);
				return result;
			}
			goto loop;
		}
#line 80 "src/codegen/subst_tags.cc"
yy4:
	++head;
yy5:
#line 31 "../src/codegen/subst_tags.re"
	{ goto loop; }
#line 86 "src/codegen/subst_tags.cc"
yy6:
	yych = *++head;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy5;
		if (yych <= '9') {
			yytag1name = (head - base);
			goto yy7;
		}
		if (yych <= '@') goto yy5;
		yytag1name = (head - base);
	} else {
		if (yych <= '_') {
			if (yych <= '^') goto yy5;
			yytag1name = (head - base);
		} else {
			if (yych <= '`') goto yy5;
			if (yych >= '{') goto yy5;
			yytag1name = (head - base);
		}
	}
yy7:
	++head;
	yych = *head;
	if (yybm[0+yych] & 128) {
		goto yy7;
	}
#line 41 "../src/codegen/subst_tags.re"
	{
			const std::string name((base + yytag1name), head);
			for (size_t i = ltag; i < htag; ++i) {
				const Tag &t = tags[i];
				if (name == *t.name) {
					result.append(tail, base);
					result.append(t.type == Tag::VAR
						? opts->input_api.expr_tag(vartag_expr(t.name, t.rule))
						: opts->input_api.expr_tag_fix(t, tags));
					tail = head;
					break;
				}
			}
			goto loop;
		}
#line 129 "src/codegen/subst_tags.cc"
}
#line 56 "../src/codegen/subst_tags.re"

}

} // namespace re2c
