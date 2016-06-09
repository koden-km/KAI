#pragma once

#include <KAI/Language/Tau/TauParser.h>

#include <strstream>
#include <string>

TAU_BEGIN

namespace Generate
{
	// common base for proxy and agent generation
	struct GenerateProcess : Process
	{
		typedef TauParser::AstNode Node;

	public:
		virtual bool Generate(TauParser const &p, const char *fname) = 0;

	protected:
		virtual bool Namespace(Node const &ns) = 0;
		virtual bool Class(Node const &cl) = 0;
		virtual bool Property(Node const &prop) = 0;
		virtual bool Method(Node const &method)  = 0;

	protected:
		std::string Prepend();
		std::stringstream &StartBlock(const std::string &text);
		std::string EndLine() const;
		void EndBlock();

		virtual std::string ArgType(std::string const &text) const = 0;
		virtual std::string ReturnType(std::string const &text) const = 0;

	protected:
		std::stringstream _str;
		int _indentation = 0;
	};
}

TAU_END

