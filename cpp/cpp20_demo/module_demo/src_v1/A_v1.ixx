export module A.test.v1;

export class Secret
{
public:
	Secret(int a) : _a(a) {}
	int _a;
};

export using Secret_alias = Secret;

export namespace A
{
	Secret MyFunc(int a, int b)
	{
		return a + 2 * b;
	}
}
