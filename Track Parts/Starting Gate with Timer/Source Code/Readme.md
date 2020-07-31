# Build tools setup

## Config dotnet Core

```bash
dotnet new console
```

## Add references

Open your .csproj file

At the end of PropertyGroup tag

```bash
<ItemGroup>
  <Reference Include="Your dll file name">
    <HintPath>Your dll file name.dll</HintPath>
    <SpecificVersion>False</SpecificVersion>
    <!-- You may set it to true if your dll has a specific version -->
  </Reference>
</ItemGroup>
```

Save the file.

Execute the command to update the project

```bash
dotnet restore
```

## Reference

[Stackoverflow](https://stackoverflow.com/questions/46815546/how-to-add-external-assembly-dll-to-net-core-2-0-on-visual-studio-code)


[Microsoft](https://docs.microsoft.com/en-us/dotnet/core/tools/dotnet-add-reference)