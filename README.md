# AutoOffsets
AutoOffsets is a software that automatically get the lastest offsets of Fortnite from a database


<div align="center">
    <img src="https://cdn.discordapp.com/attachments/931603773627977789/945400989412884480/unknown.png"/>
    <img src="https://cdn.discordapp.com/attachments/931603773627977789/945400930864623636/unknown.png"/>
</div>

# API USAGE

```lua
local Response = syn.request({
    Url = "https://fortnitereversal.xyz/index?apikey=d41d8cd98f00b204e9800998ecf8427e&offset_class=???",
    Method = "GET"
})

print(Response.Body)
```
