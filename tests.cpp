#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include <iostream>

// add your tests here

TEST_CASE("Testing solve() with long strings") {
	std::string encrypted, solved;
	
	encrypted = "Jhsjbshavy lujyfwaz lualylk alea if bzpun Jhlzhy jpwoly. Uvu-hswohilapj zftivsz (kpnpaz, dopalzwhjlz, laj.) hyl uva ayhuzmvytlk.";
	solved = "Calculator encrypts entered text by using Caesar cipher. Non-alphabetic symbols (digits, whitespaces, etc.) are not transformed.";
	CHECK(solve(encrypted) == solved);
	
	encrypted = "Xjiomvmt oj kjkpgvm wzgdza, Gjmzh Dknph dn ijo ndhkgt mviyjh ozso. Do cvn mjjon di v kdzxz ja xgvnndxvg Gvodi gdozmvopmz amjh 45 WX, hvfdib do jqzm 2000 tzvmn jgy.";
	solved = "Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old.";
	CHECK(solve(encrypted) == solved);
	
	encrypted = "Hvsfs ofs aobm jofwohwcbg ct doggousg ct Zcfsa Wdgia ojowzopzs, pih hvs aoxcfwhm vojs gittsfsr ozhsfohwcb wb gcas tcfa, pm wbxsqhsr viacif, cf fobrcawgsr kcfrg kvwqv rcb'h zccy sjsb gzwuvhzm pszwsjopzs.";
	solved = "There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable.";
	CHECK(solve(encrypted) == solved);
}

TEST_CASE("Testing solve() with short strings. Short strings will not always work.") {
	std::string encrypted, solved;
	
	encrypted = "Lipps, qc reqi mw Nslr";
	solved = "Hello, my name is John";
	CHECK(solve(encrypted) != solved);

	encrypted = "Ol pz nvpun ovtl!";
	solved = "He is going home!";
	CHECK(solve(encrypted) != solved);

	encrypted = "Nkx lgbuxozk iurux oy hrak.";
	solved = "Her favorite color is blue.";
	CHECK(solve(encrypted) == solved);
}
