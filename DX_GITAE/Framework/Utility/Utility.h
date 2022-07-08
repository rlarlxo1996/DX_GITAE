#pragma once

static string WstrToStr(wstring wStr)
{
	string result;
	result.reserve(wStr.length());

	for (auto w : wStr)
		result.push_back(w);

	return result;
}