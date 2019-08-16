// You skids probably wont be able to use this.
// But it is pretty cool.

// Supports full Vanilla Environment.
// Let me rest a bit im coming back with custom functions chill niggus.

bool ScanningDone = false;
DWORD ScriptContextVFTable = x(0x1D937C0);

namespace ScannerShit
{ 
  DWORD R_STATE;
  void Scan(DWORD offset, int threadlevel)
  { 
    // Snip, this is private and i don't want it to be leaked.
    // Its kind of slow but doesn't crash atleast.
    // It's too cool to be released ;)
    int SNIP = 0; // Snipped, the method is cool but not for skids.
    if(SNIP == 6)
    {
      ScanningDone = true;
    }
  }
}

void CreateConsole(string Title)
{
  // Double snip, this is not normal Console bypass, actually is win 32 so mhm bitches.
}

void DoConsole(string txt)
{
  // Double snip, this is not normal Console bypass, actually is win 32 so mhm bitches.
}

#define HookByScale //Snip reeee
#define SetByScale //Snip reeee


typedef int(__cdecl* lua_cachestack)(DWORD* X, int a1, int a2);
lua_cachestack cachencall = (lua_cachestack)(HookByScale(0, true, 2, false, 6, "thread")); // Doesn't reqire updating, trust me!
// No one uses this function, we could write one in C++ but why when we can ,
// easely just call an offset that Doesn't require updating and is super stable. :shrug:

// Credits to Jaden Wester for this one.
static void NopCrash(DWORD* X) {
	{
			int i, e, n;
			i = cachencall(X, 2, 1); 
			const char* theseshitty_things[] = { "0FFF8h", "xxxxxx????xxxxxxxxxxxxxxxxxxxxxxxxx" }; // Made by Buller.
      // Should nop the Crash call and Jmp to just respawn the player.
			n = e - i + 1;
      HookByScale(n, false, n, false, 52, theseshitty_things[2]);
      // Hooks the shitty method, now when we call the Hook again
      // it put together a path with the hook below this text and then be able to get the shits to change the callings!
      HookByScale(n, false, i, true, 49, theseshitty_things[1]);
      // Don't worry, should work!
      // Do not edit ANYTHING or you may get your roblox to not work anymore as it should.
      
	  const char* uhm_change_me = "call__ loc_10044510";
    HookByScale(0, false, n, false, 1, uhm_change_me);
	  uhm_change_me = "jmp__ loc_1003EE00";
    SetByScale(0, true, n, true, 1, uhm_change_me);
		DoConsole("Bypass done!");
	}
}

void AccessOffset()
{
  // Credits to Buller for the idea to crash the whole freaking check LOL.
  lua_pobject(ScannerShit::R_STATE, 999999999); //Maxing input for crashing it!
  // Crashes the offset, because roblox haven't made an crash exception.
  // So the check is now brokened but we can still use the Offset.
  // Method should not be patched if not roblox sees this!
  Sleep(120); // A little delay so we give it a little time to crash.
  // Now it is time to prevent the crash from happening. 
  // This i am not snipping!
  lua_pobject(ScannerShit::R_STATE, true); // Should also crash it but for some reason
  // it stops the freeze process :shrug:
}

// This is not patched, but you need the bypass! Releasing half of it.
typedef int(__cdecl* lua_pobj)(DWORD* X, const char* k);
lua_pobj lua_pobject = (lua_pobj)(x(0x1003ECF4)); 

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main() {
  CreateConsole("Serenity [Level 6 Bytecode]"); // Special Requirement from Josh!
  DoConsole("Scanning: ");
  ScannerShit::Scan(ScriptContextVFTable, 6); // Scans + sets the Thread Identity.
  // Lua State is already set in this scanning and libraries are opened ;)
  if(ScanningDone)
  {
    DoConsole("%Green:DONE!");
  }
  DoConsole("Bypassing: ");
  NopCrash(ScannerShit::R_STATE);
  // NopCrash takes around 6 seconds to finish.
  Sleep(4000); // Now sorry we got to sleep a little.
  // If not roblox can not prepare for the HUGE junk we are dumping.

  AccessOffset(); // Another 5 seconds.
  Sleep(1430); // Just to be sure, dont change to less it could crash!
  DoConsole("%Green:DONE!");

  // Now it is finally time to Write the Execution.
  string Script_To_Run = R"(
    local x = 1
    if x == 1 then
      print("Hello World")
    end
  )";
  replaceAll(Script_To_Run, " ", "\%|"); 
  replaceAll(Script_To_Run, "\n", "/*"); 
  replaceAll(Script_To_Run, "local", "108/"); // Dunno why actually. its in Roblox Source.
  // Not my shit, shit on Roblox's offset niggas.
  // This nigga took like 7 hours to figure out.
  lua_pobject(ScannerShit::R_STATE, Script_To_Run.c_str());
}
