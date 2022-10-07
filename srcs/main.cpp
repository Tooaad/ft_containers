/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:35:59 by gpernas-          #+#    #+#             */
/*   Updated: 2022/10/07 17:10:37 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorTests.hpp"
#include "MapTests.hpp"
#include "../includes/vector.hpp"
#include "../includes/stack.hpp"
#include "../includes/map.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>

void cleaks() { system("leaks containers"); }

int main()
{
	// runTests();
	runMapTests();
	// atexit(cleaks);

	return 0;
	
}