#include <KAI/Language/Tau/Generate/Agent.h>

using namespace std;

TAU_BEGIN

namespace Generate
{
	Agent::Agent(const char *in, const char *out)
	{
		Fail("Not Implemented");
	}

	bool Agent::Generate(TauParser const &p, const char *fname)
	{
		return false;
	}

	bool Agent::Namespace(TauParser::AstNode const &ns)
	{
		return false;
	}

	bool Agent::Class(TauParser::AstNode const &cl)
	{
		return false;
	}

	bool Agent::Property(TauParser::AstNode const &prop)
	{
		return false;
	}

	bool Agent::Method(TauParser::AstNode const &method)
	{
		return false;
	}

	std::string Agent::ArgType(std::string const &text) const
	{
		return move(text);
	}

	std::string Agent::ReturnType(std::string const &text) const
	{
		return move(text);
	}
}

TAU_END
