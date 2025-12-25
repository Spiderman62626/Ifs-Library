#pragma once

template <typename T>
struct branch // Custom data type to more efficiently store conditions and values
{
    bool cond;
    T val;
    branch(bool cond, T val)
    {
        this.cond = cond;
        this.val = val;
    }
};

template <typename T>
T ifs_(T def, branch<T> first) // Function for if/else without branching
{
    return first.cond * first.val + !first.cond * def;
}

template <typename T, typename... Args>
T ifs_(T def, branch<T> first, Args... rest) // Function for if/else if/else without branching
{
    T result = first.val * first.cond;
    bool defcond = !first.cond;
    ((result += rest.val * rest.cond, defcond *= !rest.cond), ...);
    return result + def * defcond;
}

template <typename T>
T ifs(T def, branch<T> first) // Function for if/else with branching
{
    return first.cond ? first.val : def;
}

template <typename T, typename... Args>
T ifs(T def, branch<T> first, Args... rest) // Function for if/else if with branching
{
    if (first.cond) return first.val;
    return ifs(def, rest...); // Recursion until condition is true or definition above is run
}