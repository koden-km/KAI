#pragma once

#include "KAI/Core/Base.h"
#include "KAI/Core/Argument.h"
#include "KAI/Core/Exception/FileLocation.h"
#include "KAI/Core/StringStream.h"

KAI_BEGIN

extern void DebugTrace(const char *);

namespace debug 
{
	struct Trace : StringStream
	{
		enum Type
		{
			Information,
			Warn,
			Error,
			Fatal,
		};

		Type type;
		FileLocation file_location;
		Trace(FileLocation const &F, Type T = Information) : type(T), file_location(F) { }
		~Trace();

		template <class T>
		StringStream &operator<<(const T& X)
		{
			static_cast<StringStream &>(*this) << X;
			return *this;
		}

		StringStream &operator<<(const Object& X);
		
		template <class T>
		Trace &Write(const char *P, T const &X)
		{
#ifdef KAI_TRACE_VERBOSE
			*this << "[" << P << "='" << X << "'] ";
#else
			KAI_UNUSED_1(P);
			*this << X;
#endif
			return *this;
		}
	};

	struct EmptySink
	{
		EmptySink() { }

		template <class T>
		EmptySink &operator<<(const T&)
		{
			return *this;
		}
	};
}

#	ifdef KAI_DEBUG_TRACE
#		define KAI_TRACE() \
			KAI_TRACER(__FILE__, __LINE__, "Func", Information)

#		define KAI_TRACER(F, L, N, T) \
			KAI_NAMESPACE(debug::Trace)(FileLocation(F,L,N), KAI_NAMESPACE(debug::Trace::T))

#		define KAI_TRACE_WARN() \
			KAI_TRACER(__FILE__, __LINE__, "Func", Warn)
#		define KAI_TRACE_ERROR() \
			KAI_TRACER(__FILE__, __LINE__, "Func", Error)
#		define KAI_TRACE_FATAL() \
			KAI_TRACER(__FILE__, __LINE__, "Func", Fatal)

#		define KAI_TRACE_0() \
			KAI_TRACE()
#		define KAI_TRACE_1(A) \
			KAI_TRACE().Write(#A, A)
#		define KAI_TRACE_2(A,B) \
			KAI_TRACE_1(A).Write(#B,B)
#		define KAI_TRACE_3(A,B,C) \
			KAI_TRACE_2(A,B).Write(#C,C)
#		define KAI_TRACE_4(A,B,C,D) \
			KAI_TRACE_3(A,B,Coloriser).Write(#D,D)

#		define KAI_TRACE_WARN_0() \
			KAI_TRACE_WARN()
#		define KAI_TRACE_WARN_1(A) \
			KAI_TRACE_WARN().Write(#A, A)
#		define KAI_TRACE_WARN_2(A,B) \
			KAI_TRACE_WARN_1(A).Write(#B,B)
#		define KAI_TRACE_WARN_3(A,B,C) \
			KAI_TRACE_WARN_2(A,B).Write(#C,C)
#		define KAI_TRACE_WARN_4(A,B,C,D) \
			KAI_TRACE_WARN_3(A,B,Coloriser).Write(#D,D)

#		define KAI_TRACE_ERROR_0() \
			KAI_TRACE_ERROR()
#		define KAI_TRACE_ERROR_1(A) \
			KAI_TRACE_ERROR().Write(#A, A)
#		define KAI_TRACE_ERROR_2(A,B) \
			KAI_TRACE_ERROR_1(A).Write(#B,B)
#		define KAI_TRACE_ERROR_3(A,B,C) \
			KAI_TRACE_ERROR_2(A,B).Write(#C,C)
#		define KAI_TRACE_ERROR_4(A,B,C,D) \
			KAI_TRACE_ERROR_3(A,B,Coloriser).Write(#D,D)

#	else
#		define KAI_EMPTY_TRACE_SINK debug::EmptySink()
#		define KAI_EMPTY_TRACE_SINK_1(A) debug::EmptySink()
#		define KAI_EMPTY_TRACE_SINK_2(A,B) debug::EmptySink()
#		define KAI_EMPTY_TRACE_SINK_3(A,B,C) debug::EmptySink()

#		define KAI_TRACER(F, L, N) KAI_EMPTY_TRACE_SINK
#		define KAI_TRACE()  KAI_EMPTY_TRACE_SINK
#		define KAI_TRACE_0() KAI_EMPTY_TRACE_SINK
#		define KAI_TRACE_1(A) KAI_EMPTY_TRACE_SINK_1(A)
#		define KAI_TRACE_2(A,B) KAI_EMPTY_TRACE_SINK_2(A,B)
#		define KAI_TRACE_3(A,B,C) KAI_EMPTY_TRACE_SINK_3(A,B,C)
#		define KAI_TRACE_WARN() KAI_EMPTY_TRACE_SINK
#		define KAI_TRACE_WARN_0() KAI_EMPTY_TRACE_SINK
#		define KAI_TRACE_WARN_1(A) KAI_EMPTY_TRACE_SINK_1(A)
#		define KAI_TRACE_WARN_2(A,B) KAI_EMPTY_TRACE_SINK_2(A,B)
#		define KAI_TRACE_WARN_3(A,B,C) KAI_EMPTY_TRACE_SINK_3(A,B,C)
#		define KAI_TRACE_ERROR() KAI_EMPTY_TRACE_SINK
#		define KAI_TRACE_ERROR_0() KAI_EMPTY_TRACE_SINK
#		define KAI_TRACE_ERROR_1(A) KAI_EMPTY_TRACE_SINK_1(A)
#		define KAI_TRACE_ERROR_2(A,B) KAI_EMPTY_TRACE_SINK_2(A,B)
#		define KAI_TRACE_ERROR_3(A,B,C) KAI_EMPTY_TRACE_SINK_3(A,B,C)
#	endif

KAI_END

