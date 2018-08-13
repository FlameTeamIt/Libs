#include "WideInt.hpp"

#include <Templates/AlignObject.hpp>

namespace flame_ide
{namespace test
{

using flame_ide::templates::uint40_t;
using flame_ide::Types;

WideInt::WideInt() : AbstractTest("WideInt")
{}

int WideInt::vStart()
{

	// initialization
	{
		uint40_t int40(Types::long_t(0x0102030405060708));
		uint40_t::Data data = int40.getData();
		uint40_t::Data dataValid { {
				uichar_t(0x04)
				, uichar_t(0x05)
				, uichar_t(0x06)
				, uichar_t(0x07)
				, uichar_t(0x08)
		} };
		if (data != dataValid)
		{
			Types::size_t index = 0;
			log << "data != dataValid" << std::endl;
			std::cout << "data { " << std::hex;
			for (auto i : data)
			{
				++index;
				if (index != data.size())
				{
					std::cout << int(i) << ", ";
				}
				else
				{
					std::cout << int(i);
				}
			}
			index = 0;

			std::cout << " };" << std::endl;
			std::cout << "dataValid { ";
			for (auto i : dataValid)
			{
				++index;
				if (index != dataValid.size())
				{
					std::cout << int(i) << ", ";
				}
				else
				{
					std::cout << int(i);
				}
			}
			std::cout << " };" << std::endl;
			return -1;
		}
	}

	// assign
	{
		uint40_t int40(Types::long_t(0x0102030405060708));
		int40 = Types::long_t(0x0807060504030201);
		uint40_t::Data data = int40.getData();
		uint40_t::Data dataValid { {
				Types::uichar_t(0x05)
				, Types::uichar_t(0x04)
				, Types::uichar_t(0x03)
				, Types::uichar_t(0x02)
				, Types::uichar_t(0x01)
		} };
		if (data != dataValid)
		{
			Types::size_t index = 0;
			log << "data != dataValid" << std::endl;
			std::cout << "data { " << std::hex;
			for (auto i : data)
			{
				++index;
				if (index != data.size())
				{
					std::cout << int(i) << ", ";
				}
				else
				{
					std::cout << int(i);
				}
			}
			index = 0;

			std::cout << " };" << std::endl;
			std::cout << "dataValid { ";
			for (auto i : dataValid)
			{
				++index;
				if (index != dataValid.size())
				{
					std::cout << int(i) << ", ";
				}
				else
				{
					std::cout << int(i);
				}
			}
			std::cout << " };" << std::endl;
			return -1;
		}
	}

	// convertion
	{
		uint40_t int40 = Types::long_t(0x0807060504030201);
		long_t longValue = int40;
		if (longValue != Types::long_t(0x0000000504030201))
		{
			return -1;
		}

		int40 = Types::short_t(0x1020);
		Types::short_t shortValue = int40;
		if (shortValue != 0x1020)
		{
			return -1;
		}
	}

	// reset
	{
		uint40_t int40(Types::long_t(0x0102030405060708));
		int40.reset();
		uint40_t::Data data = int40.getData();
		uint40_t::Data dataValid { {
				Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
				, Types::uichar_t(0x00)
		} };
		if (data != dataValid)
		{
			Types::size_t index = 0;
			log << "data != dataValid" << std::endl;
			std::cout << "data { " << std::hex;
			for (auto i : data)
			{
				++index;
				if (index != data.size())
				{
					std::cout << int(i) << ", ";
				}
				else
				{
					std::cout << int(i);
				}
			}
			index = 0;

			std::cout << " };" << std::endl;
			std::cout << "dataValid { ";
			for (auto i : dataValid)
			{
				++index;
				if (index != dataValid.size())
				{
					std::cout << int(i) << ", ";
				}
				else
				{
					std::cout << int(i);
				}
			}
			std::cout << " };" << std::endl;
			return -1;
		}
	}

	// binary operations
	{
		// bitwize negation
		{
			uint40_t int40(Types::long_t(0x0000000102030405));
			int40 = ~int40;
			uint40_t::Data data = int40.getData();
			uint40_t::Data dataValid {{
					Types::uichar_t(~0x01)
					, Types::uichar_t(~0x02)
					, Types::uichar_t(~0x03)
					, Types::uichar_t(~0x04)
					, Types::uichar_t(~0x05)
			}};
			if (data != dataValid)
			{
				Types::size_t index = 0;
				log << "data != dataValid" << std::endl;
				std::cout << "data { " << std::hex;
				for (auto i : data)
				{
					++index;
					if (index != data.size())
					{
						std::cout << int(i) << ", ";
					}
					else
					{
						std::cout << int(i);
					}
				}
				index = 0;

				std::cout << " };" << std::endl;
				std::cout << "dataValid { ";
				for (auto i : dataValid)
				{
					++index;
					if (index != dataValid.size())
					{
						std::cout << int(i) << ", ";
					}
					else
					{
						std::cout << int(i);
					}
				}
				std::cout << " };" << std::endl;
				return -1;
			}
		}

		// shift left

		// shift right
	}

	return 0;
}

}}
