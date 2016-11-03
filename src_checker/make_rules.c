
#include "../includes/checker.h"

static int		easy_rule(t_checker *c, char *rule)
{
	if (ft_strncmp(rule, "ss", 3) == 0)
	{
		rule_sa(c);
		rule_sb(c);
	}
	else if (ft_strncmp(rule, "rrr", 4) == 0)
	{
		rule_rra(c);
		rule_rrb(c);
	}
	else if (ft_strncmp(rule, "rr", 3) == 0)
	{
		rule_ra(c);
		rule_rb(c);
	}
	else
		return (0);
	return (1);
}

int				select_rule(t_checker *c, char *rule)
{
	if (ft_strncmp(rule, "sa", 3) == 0)
		rule_sa(c);
	else if (ft_strncmp(rule, "sb", 3) == 0)
		rule_sb(c);
	else if (ft_strncmp(rule, "pa", 3) == 0)
		rule_pa(c);
	else if (ft_strncmp(rule, "pb", 3) == 0)
		rule_pb(c);
	else if (ft_strncmp(rule, "ra", 3) == 0)
		rule_ra(c);
	else if (ft_strncmp(rule, "rb", 3) == 0)
		rule_rb(c);
	else if (ft_strncmp(rule, "rra", 4) == 0)
		rule_rra(c);
	else if (ft_strncmp(rule, "rrb", 4) == 0)
		rule_rrb(c);
	else if (easy_rule(c, rule) == 1)
		;
	else
		return (0);
	return (1);
}
