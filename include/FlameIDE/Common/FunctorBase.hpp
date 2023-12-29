#ifndef FLAMEIDE_COMMON_FUNCTORBASE_HPP
#define FLAMEIDE_COMMON_FUNCTORBASE_HPP

namespace flame_ide
{

template<typename ReturnType, typename ...Args>
struct FunctorBase
{
	virtual ~FunctorBase() noexcept = default;
	virtual ReturnType operator()(Args... args) noexcept = 0;
};
using DefaultFunctorBase = FunctorBase<void>;

template<typename ReturnType, typename ...Args>
struct FunctorConstBase
{
	virtual ~FunctorConstBase() noexcept = default;
	virtual ReturnType operator()(Args... args) const noexcept = 0;
};
using DefaultFunctorConstBase = FunctorConstBase<void>;

} // namespace flame_ide

#endif // FLAMEIDE_COMMON_FUNCTORBASE_HPP
