.code
gameinstanceshell         proc



		mov r8,[rcx+000001E8h]
		mov eax,r8d
		shr r8,20h ;{ 32 }
		xor r8d,0FE2EC6E8h ;{ -30488856 }
		xor eax,099FF03BDh ;{ -1711340611 }
		ror r8d,08h ;{ 8 }
		ror eax,10h ;{ 16 }
		add r8d,0330B330Ch ;{ 856371980 }
		add eax,034B4E48Ch ;{ 884270220 }
		xor r8d,0992EC6E8h ;{ -1724987672 }
		xor eax,034FF03BDh ;{ 889127869 }
		ror r8d,08h ;{ 8 }
		ror eax,10h ;{ 16 }
		xor r8d,0CCF4CCF4h ;{ -856371980 }
		xor eax,034B4E48Ch ;{ 884270220 }
		;mov [rsp+00000084h],r8d
		;mov [rsp+00000080h],eax
		;mov rbx,[rsp+00000080h]
		shl r8,20h
		add r8,rax
		mov rax,r8
		ret


gameinstanceshell         endp


localplayershell         proc                    
                                        


		mov rcx,[rcx]
		mov [rsp+50h],r15
		lea eax,[rcx-2145BF43h]
		shr rcx,20h ;{ 32 }
		ror eax,08h ;{ 8 }
		sub ecx,025173F59h ;{ 622280537 }
		sub eax,04D2C89CCh ;{ 1294764492 }
		xor ecx,047E94729h ;{ 1206470441 }
		ror eax,08h ;{ 8 }
		xor eax,039193577h ;{ 0.00 }
		;mov [rsp+54],ecx
		;mov [rsp+50],eax
		;mov rsi,[rsp+50]



		shl rcx,20h
		add rcx,rax
		mov rax,rcx
		ret





      


	

localplayershell         endp


localplayercontrollershell         proc                    
                                        


		mov rax,[rcx+38h]
		;mov rbx,rcx
		;xor edi,edi
		;mov [rbp+10],rdi
		lea ecx,[rax-1CC87571h]
		shr rax,20h ;{ 32 }
		add eax,54D8D578h ;{ 1423496568 }
		rol ecx,08h ;{ 8 }
		ror eax,10h ;{ 16 }
		sub ecx,7E9881B0h ;{ 2123923888 }
		add eax,71F963D9h ;{ 1912169433 }
		ror ecx,10h ;{ 16 }
		ror eax,08h ;{ 8 }
		xor ecx,0F2FF3C1h ;{ 254800833 }
		xor eax,71DF719Fh ;{ 1910469023 }
		;mov [rbp+10],ecx
		;mov [rbp+14],eax
		;cmp [rbp+10],rdi





		shl rax,20h
		add rax,rcx
		;mov rax,rcx
		ret





      


	

localplayercontrollershell         endp



 
end